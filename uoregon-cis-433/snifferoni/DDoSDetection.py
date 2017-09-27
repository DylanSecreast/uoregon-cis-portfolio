#!/usr/bin/python
import time;
import numpy;
import twitter;
import ConfigParser;
#MARK: Classes
#PacketPopulation will be populated by all currently stored PacketSamples
class PacketPopulation():

	def __init__(self):
		self.packetSamples = []
		self.numCaptures = 0
		self.totalPacketsCaptured = {"TCP": 0, "UDP": 0, "SYN": 0, "ICMP": 0, "Any": 0 }

class PacketSample():

	def __init__(self):
		self.time = time.localtime(time.time())
		self.numPackets = {"TCP": 0, "UDP": 0, "SYN": 0, "ICMP": 0, "Any": 0 }
		self.averagePackets = {"TCP": 0, "UDP": 0, "SYN": 0, "ICMP": 0, "Any": 0 }
		self.upperboundInner = {"TCP": 0, "UDP": 0, "SYN": 0, "ICMP": 0, "Any": 0 }
		self.upperboundOuter = {"TCP": 0, "UDP": 0, "SYN": 0, "ICMP": 0, "Any": 0 }
		self.percentages = {"TCP": 0, "UDP": 0, "SYN": 0, "ICMP": 0}


#MARK: Functions
def analyze(PacketPopulation, newSample):

	targetSample = PacketPopulation.packetSamples


	#New packetpopulation
	tcpPackets = []
	udpPackets = []
	synPackets = []
	icmpPackets = []
	anyPackets = []
	packetSamples = targetSample

	#Filter by packet type
	for packetSample in packetSamples:
		if packetSample.numPackets['TCP']:
			tcpPackets.append(packetSample.numPackets['TCP'])
		if packetSample.numPackets['UDP']:
			udpPackets.append(packetSample.numPackets['UDP'])
		if packetSample.numPackets['SYN']:
			synPackets.append(packetSample.numPackets['SYN'])
		if packetSample.numPackets['ICMP']:
			icmpPackets.append(packetSample.numPackets['ICMP'])
		if packetSample.numPackets['Any']:
			anyPackets.append(packetSample.numPackets['Any'])


	#Analyze TCP
	if len(tcpPackets):
		newSample.averagePackets['TCP'] = numpy.average(tcpPackets)
		newSample.percentages['TCP'] = round(percentage(newSample.numPackets['TCP'],newSample.numPackets['Any']),2)
		newSample.upperboundInner['TCP'] = calcUpperboundInner(tcpPackets)
		newSample.upperboundOuter['TCP'] = calcUpperboundOuter(tcpPackets)
	#Analyze UDP
	if len(udpPackets):
		newSample.averagePackets['UDP'] = numpy.average(udpPackets)
		newSample.percentages['UDP'] = round(percentage(newSample.numPackets['UDP'],newSample.numPackets['Any']),2)
		newSample.upperboundInner['UDP'] = calcUpperboundInner(udpPackets)
		newSample.upperboundOuter['UDP'] = calcUpperboundOuter(udpPackets)
	#Analyze SYN
	if len(synPackets):
		newSample.averagePackets['SYN'] = numpy.average(synPackets)
		newSample.percentages['SYN'] = round(percentage(newSample.numPackets['SYN'],newSample.numPackets['Any']),2)
		newSample.upperboundInner['SYN'] = calcUpperboundInner(synPackets)
		newSample.upperboundOuter['SYN'] = calcUpperboundOuter(synPackets)
	#Analyze ICMP
	if len(icmpPackets):
		newSample.averagePackets['ICMP'] = numpy.average(icmpPackets)
		newSample.percentages['ICMP'] = round(percentage(newSample.numPackets['ICMP'],newSample.numPackets['Any']),2)
		newSample.upperboundInner['ICMP'] = calcUpperboundInner(icmpPackets)
		newSample.upperboundOuter['ICMP'] = calcUpperboundOuter(icmpPackets)
	#Analyze total
	if len(anyPackets):
		newSample.averagePackets['Any'] = numpy.average(anyPackets)
		newSample.upperboundInner['Any'] = calcUpperboundInner(anyPackets)
		newSample.upperboundOuter['Any'] = calcUpperboundOuter(anyPackets)

	#Add new data
	tcpPackets.append(newSample.numPackets['TCP'])
	udpPackets.append(newSample.numPackets['UDP'])
	synPackets.append(newSample.numPackets['SYN'])
	icmpPackets.append(newSample.numPackets['ICMP'])
	anyPackets.append(newSample.numPackets['Any'])

	newPacketPopulation = updatePopulation(PacketPopulation, newSample)

	return newPacketPopulation

def calcUpperboundInner(packetPoints):
	packetPoints.sort()
	q1 = numpy.percentile(packetPoints, 25)
	q3 = numpy.percentile(packetPoints, 75)
	iqr = q3-q1
	r = iqr * 1.5
	upperRange = packetPoints[len(packetPoints)/2:]
	upperbound = numpy.median(upperRange) + r
	return upperbound

def calcUpperboundOuter(packetPoints):
	packetPoints.sort()
	q1 = numpy.percentile(packetPoints, 25)
	q3 = numpy.percentile(packetPoints, 75)
	iqr = q3-q1
	r = iqr * 3
	upperRange = packetPoints[len(packetPoints)/2:]
	upperbound = numpy.median(upperRange) + r
	return upperbound

def percentage(part, whole):
  return 100 * float(part)/float(whole)

def updatePopulation(population, sample):
	population.totalPacketsCaptured['TCP'] += sample.numPackets['TCP']
	population.totalPacketsCaptured['UDP'] += sample.numPackets['UDP']
	population.totalPacketsCaptured['ICMP'] += sample.numPackets['ICMP']
	population.totalPacketsCaptured['SYN'] += sample.numPackets['SYN']
	population.numCaptures += 1
	population.packetSamples.append(sample)
	return population

def postTweet(message):
	try:
		api = twitter.Api(
			consumer_key = 'F2CzqtWue9tvcHmmilectrCX7',
			consumer_secret = '5Byq1NiziCIed8eAobQyOdS3wNLYjOjVSJPbZ8wKMKPlajO0Ix',
			access_token_key = '838504742552662017-hF6vEuxlsIpEFVIsPv6lrQZhUhRIEFe',
			access_token_secret = 'AjbdO8DOrWLmOJVHohSoMAUmwL8ieKnY8ZUBQWDvW5O2Q'
		)
		status = api.PostUpdate(message)
        	print "Successfully posted %s as %s" % (status.text, status.user.name)
	except:
		print "Error posting tweet"


def determineAttack(packetSample):

	#Determine if above average traffic
	largestPacketType = 'None'
	maxNum = 0
	for key in packetSample.numPackets:
		if(key != 'Any'):
			if(maxNum < packetSample.numPackets[key]):
				maxNum = packetSample.numPackets[key]
				largestPacketType = key

	#Check if number of packets is larger than normal for given packet traffic
	if(packetSample.numPackets[largestPacketType] > packetSample.averagePackets[largestPacketType]):
		message = "There are more %s packets than normal..." % largestPacketType
		postTweet(message)
		print message
		print "Percentage of traffic of type %s : %s" % (largestPacketType, str(packetSample.percentages[largestPacketType]))
		#Check if minor outlier
		if(packetSample.numPackets[largestPacketType] > packetSample.upperboundInner[largestPacketType]):
			#Check if major outlier
			if(packetSample.numPackets[largestPacketType] > packetSample.upperboundOuter[largestPacketType]):
				#Determine if high percentage of total traffic
				if(packetSample.percentages[largestPacketType] > 95.0):
					message = "DDoS Attack detected of type : %s" % largestPacketType
					postTweet(message)
					print message
					return
				message = "Possible DDoS Attack detected of type : %s" % largestPacketType
				postTweet(message)
				print message
				return
			message = "DDoS Attack detected of type : %s" % largestPacketType
			postTweet(message)
			print message
			return
		print "But it is not an outlier"
	return
