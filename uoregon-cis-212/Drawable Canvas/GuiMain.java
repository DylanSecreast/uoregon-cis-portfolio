package com.dylansecreast.core;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class GuiMain  {
	private static Canvas canvas = new Canvas();

	public static void main(String[] args) {
	
		//// FRAME ////
		JFrame frame = new JFrame("Drawable Canvas by Dylan Secreast");
		frame.setBounds(50,50,500,400);
		frame.setLayout(new BorderLayout());
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		frame.setResizable(false);
		
		/// BUTTONS ////
		JPanel colorPanel = new JPanel();
		JPanel sizePanel = new JPanel();
		
		JButton blackBtn = new JButton("Black");
		blackBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				canvas.setColor(Color.BLACK);
			}
		});
		colorPanel.add(blackBtn);
		
		JButton greenBtn = new JButton("Green");
		greenBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				canvas.setColor(Color.GREEN);
			}
		});
		colorPanel.add(greenBtn);
		
		JButton yellowBtn = new JButton("Yellow");
		yellowBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				canvas.setColor(Color.YELLOW);
			}
		});
		colorPanel.add(yellowBtn);
		
		JButton grayBtn = new JButton("Gray");
		grayBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				canvas.setColor(Color.GRAY);
			}
		});
		colorPanel.add(grayBtn);
		frame.add(colorPanel, BorderLayout.NORTH);
		
		JButton smallBtn = new JButton("Small");
		smallBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				canvas.setSize(7);
			}
		});
		sizePanel.add(smallBtn);
		
		JButton mediumBtn = new JButton("Medium");
		mediumBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				canvas.setSize(12);
			}
		});
		sizePanel.add(mediumBtn);
		
		JButton largeBtn = new JButton("Large");
		largeBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				canvas.setSize(20);
			}
		});
		sizePanel.add(largeBtn);
		
		JButton clearBtn = new JButton("Clear");
		clearBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				canvas.clearList();
			}
		});
		sizePanel.add(clearBtn);
		frame.add(sizePanel, BorderLayout.SOUTH);
		
		//// CANVAS ////
		frame.add(canvas, BorderLayout.CENTER);

	}	// end main()
}
