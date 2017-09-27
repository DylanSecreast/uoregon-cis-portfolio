# Dylan Secreast
# CIS 471 - Project 3
# 11/28/16

# analysis.py
# -----------
# Licensing Information: Please do not distribute or publish solutions to this
# project. You are free to use and extend these projects for educational
# purposes. The Pacman AI projects were developed at UC Berkeley, primarily by
# John DeNero (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# For more info, see http://inst.eecs.berkeley.edu/~cs188/sp09/pacman.html

######################
# ANALYSIS QUESTIONS #
######################

# Change these default values to obtain the specified policies through
# value iteration.

def question2():
  answerDiscount = 0.9
  answerNoise = 0.01
  return answerDiscount, answerNoise

# Prefer the close exit (+1), risking the cliff (-10)
def question3a():
  answerDiscount = 0.1
  answerNoise = 0.0001
  answerLivingReward = 0.8
  return answerDiscount, answerNoise, answerLivingReward

# Prefer the close exit (+1), but avoiding the cliff (-10)
def question3b():
  answerDiscount = 0.1
  answerNoise = 0.001
  answerLivingReward = 0.8
  return answerDiscount, answerNoise, answerLivingReward

# Prefer the distant exit (+10), risking the cliff (-10)
def question3c():
  answerDiscount = 0.9
  answerNoise = 0.01
  answerLivingReward = 0.2
  return answerDiscount, answerNoise, answerLivingReward

# Prefer the distant exit (+10), avoiding the cliff (-10)
def question3d():
  answerDiscount = 0.9
  answerNoise = 0.2
  answerLivingReward = 0.2
  return answerDiscount, answerNoise, answerLivingReward

# Avoid both exits (also avoiding the cliff)
def question3e():
  answerDiscount = 0.9
  answerNoise = 0.2
  answerLivingReward = 1.0
  return answerDiscount, answerNoise, answerLivingReward

# Is there an epsilon and a learning rate for which it is highly likely
# (greater than 99%) that the optimal policy will be learned after 50 iterations?
def question6():
  answerEpsilon = None
  answerLearningRate = None
  return 'NOT POSSIBLE'

if __name__ == '__main__':
  print 'Answers to analysis questions:'
  import analysis
  for q in [q for q in dir(analysis) if q.startswith('question')]:
    response = getattr(analysis, q)()
    print '  Question %s:\t%s' % (q, str(response))
