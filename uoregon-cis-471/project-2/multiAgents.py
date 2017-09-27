# Dylan Secreast
# CIS 471
# 11/7/16

# multiAgents.py
# --------------
# Licensing Information: Please do not distribute or publish solutions to this
# project. You are free to use and extend these projects for educational
# purposes. The Pacman AI projects were developed at UC Berkeley, primarily by
# John DeNero (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# For more info, see http://inst.eecs.berkeley.edu/~cs188/sp09/pacman.html

from util import manhattanDistance
from game import Directions
import random, util
import sys

from game import Agent

class ReflexAgent(Agent):
  """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
  """


  def getAction(self, gameState):
    """
    You do not need to change this method, but you're welcome to.

    getAction chooses among the best options according to the evaluation function.

    Just like in the previous project, getAction takes a GameState and returns
    some Directions.X for some X in the set {North, South, West, East, Stop}
    """
    # Collect legal moves and successor states
    legalMoves = gameState.getLegalActions()

    # Choose one of the best actions
    scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
    bestScore = max(scores)
    bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
    chosenIndex = random.choice(bestIndices) # Pick randomly among the best

    "Add more of your code here if you want to"

    return legalMoves[chosenIndex]

  def evaluationFunction(self, currentGameState, action):
    """
    Design a better evaluation function here.

    The evaluation function takes in the current and proposed successor
    GameStates (pacman.py) and returns a number, where higher numbers are better.

    The code below extracts some useful information from the state, like the
    remaining food (newFood) and Pacman position after moving (newPos).
    newScaredTimes holds the number of moves that each ghost will remain
    scared because of Pacman having eaten a power pellet.

    Print out these variables to see what you're getting, then combine them
    to create a masterful evaluation function.
    """
    # Useful information you can extract from a GameState (pacman.py)
    successorGameState = currentGameState.generatePacmanSuccessor(action)
    newPos = successorGameState.getPacmanPosition()
    newFood = successorGameState.getFood()
    newGhostStates = successorGameState.getGhostStates()
    newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

    "*** YOUR CODE HERE ***"
    heuristic = 0
    succScore = successorGameState.getScore()
    foodList = currentGameState.getFood().asList()
    currentNumFood = currentGameState.getNumFood()
    succNumFood = successorGameState.getNumFood()

    # Get closest ghost
    closestGhost = float("inf")
    for ghost in newGhostStates:
        currentDist = manhattanDistance(newPos, ghost.getPosition())
        if currentDist < closestGhost:
            closestGhost = currentDist

    if closestGhost <= 3:       # If closest ghost is at least 3 spaces away
        return -float("inf")    # Run away, Pacman!
    else:
        heuristic = succScore + closestGhost

    # Ghosts are not close, get closest food
    closestFood = float("inf")
    for food in foodList:
        currentDist = util.manhattanDistance(newPos, food)
        if (currentDist < closestFood):
            closestFood = currentDist
    if (currentNumFood > succNumFood):  # Found a pellet to eat
        heuristic += 100    # Encourage Pacman to eat pellet

    heuristic -= 3 * closestFood

    return heuristic

def scoreEvaluationFunction(currentGameState):
  """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
  """
  return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
  """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
  """

  def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
    self.index = 0 # Pacman is always agent index 0
    self.evaluationFunction = util.lookup(evalFn, globals())
    self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
  """
    Your minimax agent (question 2)
  """

  def getAction(self, gameState):
    """
      Returns the minimax action from the current gameState using self.depth
      and self.evaluationFunction.

      Here are some method calls that might be useful when implementing minimax.

      gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

      Directions.STOP:
        The stop direction, which is always legal

      gameState.generateSuccessor(agentIndex, action):
        Returns the successor game state after an agent takes an action

      gameState.getNumAgents():
        Returns the total number of agents in the game
    """
    "*** YOUR CODE HERE ***"
    # Minimax algorithm: p. 166
    #
    # function Minimax-Decision(state) returns an action
    #   return max(min-value(result(state, a)))
    #
    # function Max-Value(state) returns a utility value
    #   if terminal-test(state) then return utility(state)
    #   v <- -float("inf")
    #   for each a in actions(state) do
    #     v <- max(v, min-value(result(s, a)))
    #   return v
    #
    # function Min-Value(state) returns a utility value
    #   if terminal-test(state) then return utility(state)
    #   v <- float("inf")
    #   for each a in actions(state) do
    #       v <- min(v, max-value(result(s, a)))
    #   return v
    #
    # minimax-decision(state)

    score = -float("inf")
    decision = Directions.STOP
    ghosts = gameState.getNumAgents() - 1
    allLegalActions = gameState.getLegalActions()

    def MaxValue(gameState, depth, ghosts):
        if depth == 0 or gameState.isLose() or gameState.isWin():   # if terminal-test(state)
            return self.evaluationFunction(gameState)               # then return utility(state)

        allLegalActions = gameState.getLegalActions(0)              # get all legal actions
        v = -float("inf")                                           # initialize v

        for action in allLegalActions:                              # for each a in actions(state) do
            result = gameState.generateSuccessor(0, action)         # calculate new action
            minValue = MinValue(result, depth - 1, 1, ghosts)       # get min value
            v = max(v, minValue)                                    # v <- min(v, max-value(result(s, a)))

        return v

    def MinValue(gameState, depth, agentIndex, ghosts):
        if depth == 0 or gameState.isLose() or gameState.isWin():   # if terminal-test(state)
            return self.evaluationFunction(gameState)               # then return utility(state)

        allLegalActions = gameState.getLegalActions(agentIndex)     # get all legal actions
        v = float("inf")                                            # initialize v

        if  ghosts == agentIndex:
            for action in allLegalActions:                                  # for each a in actions(state) do
                result = gameState.generateSuccessor(agentIndex, action)    # calculate new action
                maxValue = MaxValue(result, depth - 1, ghosts)              # calculate max value
                v = min(v, maxValue)                                        # v <- min(v, max-value(result(s, a)))
        else:
            for action in allLegalActions:                                  # for each a in actions(state) do
                result = gameState.generateSuccessor(agentIndex, action)    # calculate new action
                minValue = MinValue(result, depth, agentIndex + 1, ghosts)  # calculate min value
                v = min(v, minValue)                                        # v <- min(v, max-value(result(s, a)))

        return v

    for action in allLegalActions:
        result = gameState.generateSuccessor(0, action)
        succScore = score
        depth = self.depth
        minValue = MinValue(result, depth, 1, ghosts)
        score = max(score, minValue)
        if succScore < score:   # if we found a better score
            decision = action   # set new decision
    return decision

class AlphaBetaAgent(MultiAgentSearchAgent):
  """
    Your minimax agent with alpha-beta pruning (question 3)
  """

  def getAction(self, gameState):
    """
      Returns the minimax action using self.depth and self.evaluationFunction
    """
    "*** YOUR CODE HERE ***"
    # Alpha-beta search algorithm: p. 170
    #
    # fuction Alpha-Beta-Search(state) returns an action
    #   v <- Max-Value(state, -float("inf"), +float("inf"))
    #   return the action in Actions(state) with value v
    #
    # function Max-Value(state,alpha,beta) returns a utility value
    #   if Terminal-Test(state) then return Utility(state)
    #   v <- float("inf")
    #   for each a in Actions(state) do
    #       v <- Max(v, Min-Value(Result(s,a),alpha,beta))
    #       if v >= beta then return v
    #       alpha <- Max(alpha,v)
    #   return v
    #
    # function Min-Value(state,alpha,beta) returns a utility value
    #   if Terminal-Test(state) then return Utility(state)
    #   v <- +float("inf")
    #   for each a in Actions(state) do
    #       v <- Min(v, Max-Value(Result(s,a),alpha,beta))
    #       if v =< alpha then return v
    #       beta <- Min(beta, v)
    #   return v

    def MaxValue(gameState, alpha, beta, depth):
        if depth == 0 or gameState.isLose() or gameState.isWin():   # if Terminal-Test(state)
            return self.evaluationFunction(gameState)               # then return Utility(state)

        allLegalActions = gameState.getLegalActions(0)              # get all legal actions
        ghosts = gameState.getNumAgents() - 1                       # get current num of ghosts
        v = -float("inf")                                           # initialize v

        for action in allLegalActions:
            result = gameState.generateSuccessor(0, action)         # calculate new action
            minValue = MinValue(result, alpha, beta, ghosts, depth) # calculate min value
            v = max(v, minValue)                                    # get max value

            if v >= beta:   # if we can stop expanding nodes
                return v    # return max value
            alpha = max(alpha, v)   # set new alpha

        return v

    def MinValue(gameState, alpha, beta, agentIndex, depth):
        if depth == 0 or gameState.isLose() or gameState.isWin():   # if Terminal-Test(state)
            return self.evaluationFunction(gameState)               # then return Utility(state)

        allLegalActions = gameState.getLegalActions(agentIndex)     # Get all legal actions
        ghosts = gameState.getNumAgents() - 1                       # get current num of ghosts
        v = float("inf")                                            # initialize v

        for action in allLegalActions:
            result = gameState.generateSuccessor(agentIndex, action)    # calculate new action
            if ghosts == agentIndex:
                maxValue = MaxValue(result, alpha, beta, depth - 1)  # calculate max value
                v = min(v, maxValue)                                    # set v to min value
                if v <= alpha:  # if we can stop,
                    return v    # then lets stop
                beta = min(beta, v) # otherwise, keep going
            else:
                minValue = MinValue(result, alpha, beta, agentIndex + 1, depth) # calculate min value
                v = min(v, minValue)    # set v to min value
                if v <= alpha:  # if we can stop,
                    return v    # stop
                beta = min(beta, v) # otherwise, keep going
        return v

    alpha = -float("inf")
    beta = float("inf")
    score = -float("inf")
    decision = Directions.STOP
    allLegalActions = gameState.getLegalActions(0)

    for action in allLegalActions:
        result = gameState.generateSuccessor(0, action)
        currentScore = score
        minValue = MinValue(result, alpha, beta, 1, self.depth)
        score = max(score, minValue)

        if currentScore < score:    # if we found a better score
            decision = action   # set new decision
        if score >= beta:   # if score is as good as it's going to get,
            return decision

        alpha = max(alpha, score)   # otherwise, keep going

    return decision


class ExpectimaxAgent(MultiAgentSearchAgent):
  """
    Your expectimax agent (question 4)
  """

  def getAction(self, gameState):
    """
      Returns the expectimax action using self.depth and self.evaluationFunction

      All ghosts should be modeled as choosing uniformly at random from their
      legal moves.
    """
    "*** YOUR CODE HERE ***"
    # Expectimax Pseudocode, 10/17/12 slides, p. 7
    #
    # def value(s)
    #   if s is a max node return maxValue(s)
    #   if s is an exp node return expValue(s)
    #   if s is a terminal node return evaluation(s)
    #
    # def maxValue(s)
    #   values = [value(s') for s' in successors(s)]
    #   return max(values)
    #
    # def expValue(s)
    #   values = [value(s') for s' in successors(s)]
    #   weights = [probability(s, s') for s' in successors(s)]
    #   return expectation(values, weights)

    return self.findBestAction(gameState, self.depth, 0)[1]

  def findBestAction(self, gameState, depth, agentIndex):
    if depth == 0 or gameState.isLose() or gameState.isWin():
        return (self.evaluationFunction(gameState), "")

    decision = ""
    ghosts = gameState.getNumAgents() - 1
    newAgentIndex = (agentIndex + 1) % (ghosts + 1)
    allLegalActions = gameState.getLegalActions(agentIndex)

    if agentIndex == 0:
        alpha = -float("inf")
    else:
        alpha = 0

    if ghosts == agentIndex:
        depth -= 1

    for action in allLegalActions:
        result = gameState.generateSuccessor(agentIndex, action)
        nextAction = self.findBestAction(result, depth, newAgentIndex)

        if agentIndex == 0:
            if alpha < nextAction[0]:
                alpha = nextAction[0]
                decision = action
        else:
            weight = 1.0 / len(allLegalActions)
            alpha += nextAction[0] * weight
            decision = action

    return (alpha, decision)

def betterEvaluationFunction(currentGameState):
  """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
    evaluation function (question 5).

    DESCRIPTION: betterEvaluationFunction takes current game score, remaining food pellets, remaining power pellets, and number of ghosts into a linear combination of features. I have arbitrarily determined various "importance values" for each of the listed variables, summing to a heuristic that is then returned as its reciprocal value.
  """
  "*** YOUR CODE HERE ***"
  heuristic = 0
  lowImportance = 100
  highImportance = 1000
  score = currentGameState.getScore()
  pacman = currentGameState.getPacmanPosition()
  foodList = currentGameState.getFood().asList()
  numFood = currentGameState.getNumFood()
  powerPellets = currentGameState.getCapsules()
  numPowerPellets = len(powerPellets)
  currentGhosts = currentGameState.getGhostPositions()
  distance = float("inf")
  isDistSet = False

  #
  for food in foodList:
    currentDist = util.manhattanDistance(pacman, food)
    if currentDist < distance:
        distance = currentDist
        isDistSet = True

  # Only add distance to heuristic if it's been set
  if isDistSet:
    heuristic += distance

  # Arbiturary importance calculation
  heuristic += (highImportance * numFood) + (lowImportance * numPowerPellets)

  # Account for ghosts
  for ghost in currentGhosts:
      currentDist = util.manhattanDistance(pacman, ghost)
      if currentDist < 2:   # Ghost is close! run away
          heuristic = sys.maxint    # breaks on float("inf")

  heuristic -= (lowImportance * score)

  return -heuristic

# Abbreviation
better = betterEvaluationFunction

class ContestAgent(MultiAgentSearchAgent):
  """
    Your agent for the mini-contest
  """

  def getAction(self, gameState):
    """
      Returns an action.  You can use any method you want and search to any depth you want.
      Just remember that the mini-contest is timed, so you have to trade off speed and computation.

      Ghosts don't behave randomly anymore, but they aren't perfect either -- they'll usually
      just make a beeline straight towards Pacman (or away from him if they're scared!)
    """
    "*** YOUR CODE HERE ***"
    util.raiseNotDefined()
