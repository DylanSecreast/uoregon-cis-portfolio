//
//  HomeViewController.swift
//  TotalTime
//
//  Created by Dylan Secreast on 3/1/17.
//  Copyright © 2017 Dylan Secreast. All rights reserved.
//

import Foundation
import UIKit
import CoreData
import AVFoundation

class HomeViewController : UIViewController, NSFetchedResultsControllerDelegate {
    @IBOutlet weak var timerLabel: UILabel!
    @IBOutlet weak var currentJobLabel: UILabel!
    @IBOutlet weak var currentTotalTabel: UILabel!
    
    private var jobFetchedResultsController: NSFetchedResultsController<Job>!
    private var audioPlayer: AVAudioPlayer!
    
    var jobs: [Job] = []
    var timer: Timer = Timer()
    var startTime = TimeInterval()
    
    @IBAction func start(_ sender: UIButton) {
        // Verify user has entered minimum necessary job info to start
        if (jobs.count == 0) {
            let alertController = UIAlertController(title: "Wait a Minute!", message: "Please enter Job Title and Hourly Rate under the Job tab to begin.", preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
            present(alertController, animated: true, completion: nil)
            return
        }
        
        
        if (timer.isValid) {    // Timer already started
            let alertController = UIAlertController(title: "On The Clock", message: "Timer has already started. Stop to restart.", preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
            present(alertController, animated: true, completion: nil)
        }
        else {  // Timer not started
            currentJobLabel.text = jobs.last?.title
            
            let audioFilePath = Bundle.main.path(forResource: "train", ofType: "mp3")
            
            if (audioFilePath != nil) {
                let audioFileUrl = NSURL.init(fileURLWithPath: audioFilePath!)
                do {
                    try audioPlayer = AVAudioPlayer(contentsOf: audioFileUrl as URL)
                    audioPlayer.play()
                }
                catch {
                    print("Unable to play train.mp3")
                }
            }
            else {
                print("Unable to find train.mp3")
            }
            
            let aSelector: Selector = #selector(HomeViewController.updateTime)
            timer = Timer.scheduledTimer(timeInterval: 1, target: self, selector: aSelector, userInfo: nil, repeats: true)
            startTime = Date.timeIntervalSinceReferenceDate
        }
        
    }
    
    @IBAction func stop(_ sender: UIButton) {
        timer.invalidate()
        audioPlayer.stop()
        currentJobLabel.text = "Job Complete!"
        
        let alertController = UIAlertController(title: "Get Paid!", message: "Your invoice is ready to view under the Done tab", preferredStyle: .alert)
        alertController.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
        present(alertController, animated: true, completion: nil)
    }

    public func updateTime() {
        let currentTime = Date.timeIntervalSinceReferenceDate
        var elapsedTime: TimeInterval = currentTime - startTime
        
        let minutes = UInt8(elapsedTime / 60.0)
        elapsedTime -= (TimeInterval(minutes) * 60)
        
        let seconds = UInt8(elapsedTime)
        elapsedTime -= TimeInterval(seconds)
        
        // Play gentle sound notification every 15min
        if (minutes % 15 == 0) {
            audioPlayer.play()
        }
        
        let strMinutes = String(format: "%02d", minutes)
        let strSeconds = String(format: "%02d", seconds)
        
        timerLabel.text = "\(strMinutes):\(strSeconds)"
        
        calculateTotal(min: minutes, sec: seconds)
    }

    public func calculateTotal(min: UInt8, sec: UInt8) {
        let totalSecondsWorked = Float((min * 60) + sec)
        let hourlyRate: Float = (jobs.last?.hourlyRate)!
        let commision = hourlyRate * (totalSecondsWorked / 3600)
        
        currentTotalTabel.text = "$" + String(format: "%.2f", commision)
    }
    
    func fetchData() {
        jobFetchedResultsController = TimeService.shared.jobData()
        jobFetchedResultsController.delegate = self
        jobs = jobFetchedResultsController.fetchedObjects!
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        
        fetchData()
        
        currentJobLabel.text = jobs.last?.title
    }
    
    func controllerDidChangeContent(_ controller: NSFetchedResultsController<NSFetchRequestResult>) {
        fetchData()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    

    
    
}
