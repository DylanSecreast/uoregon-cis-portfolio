# Dylan Secreast
# CIS 471 - Prof. Lowd
# Project 1B - 10/11/16
#
# This is my own work except for the following:
#   - Base code provided by Prof. Lowd.
#   - Comments in DFS, BFS, UCS, and A* functions are pesudocode from Figures
#       3.7, 3.11, 3.13, and 3.16 respectivly (R&N 3ed Section 3).

# search.py
# ---------
# Licensing Information: Please do not distribute or publish solutions to this
# project. You are free to use and extend these projects for educational
# purposes. The Pacman AI projects were developed at UC Berkeley, primarily by
# John DeNero (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# For more info, see http://inst.eecs.berkeley.edu/~cs188/sp09/pacman.html

"""
In search.py, you will implement generic search algorithms which are called
by Pacman agents (in searchAgents.py).
"""

import util

class SearchProblem:
  """
  This class outlines the structure of a search problem, but doesn't implement
  any of the methods (in object-oriented terminology: an abstract class).

  You do not need to change anything in this class, ever.
  """

  def getStartState(self):
     """
     Returns the start state for the search problem
     """
     util.raiseNotDefined()

  def isGoalState(self, state):
     """
       state: Search state

     Returns True if and only if the state is a valid goal state
     """
     util.raiseNotDefined()

  def getSuccessors(self, state):
     """
       state: Search state

     For a given state, this should return a list of triples,
     (successor, action, stepCost), where 'successor' is a
     successor to the current state, 'action' is the action
     required to get there, and 'stepCost' is the incremental
     cost of expanding to that successor
     """
     util.raiseNotDefined()

  def getCostOfActions(self, actions):
     """
      actions: A list of actions to take

     This method returns the total cost of a particular sequence of actions.  The sequence must
     be composed of legal moves
     """
     util.raiseNotDefined()


def tinyMazeSearch(problem):
  """
  Returns a sequence of moves that solves tinyMaze.  For any other
  maze, the sequence of moves will be incorrect, so only use this for tinyMaze
  """
  from game import Directions
  s = Directions.SOUTH
  w = Directions.WEST
  return  [s,s,w,s,w,w,s,w]

def depthFirstSearch(problem):
  """
  Search the deepest nodes in the search tree first [p 85].

  Your search algorithm needs to return a list of actions that reaches
  the goal.  Make sure to implement a graph search algorithm [Fig. 3.7].

  To get started, you might want to try some of these simple commands to
  understand the search problem that is being passed in:

  print "Start:", problem.getStartState()
  print "Is the start a goal?", problem.isGoalState(problem.getStartState())
  print "Start's successors:", problem.getSuccessors(problem.getStartState())
  """
  "*** YOUR CODE HERE ***"
  startState = problem.getStartState()   # Get initial start state
  if problem.isGoalState(startState):  # Base case: If start is goal
    return startState    # Return starting state
  fringe = util.Stack() # Initialize tfringe as stack
  fringe.push((startState, [], []))    # Push start state onto fringe
  while not fringe.isEmpty():   # While there are unexplored fringe nodes in stack
      node, sequence, history = fringe.pop() # Remove first leaf from frontier
      for coords, heading, steps in problem.getSuccessors(node): # Expand chosen node
          if not coords in history:  # If coords have not been explored
              if problem.isGoalState(coords):    # If we reached the goal state
                  return sequence + [heading]  # Return solution
              fringe.push((coords, sequence + [heading], history + [node])) # Add node to explored set
  return []   # If frontier is empty, return failure

def breadthFirstSearch(problem):
  "Search the shallowest nodes in the search tree first. [p 81]"
  "*** YOUR CODE HERE ***"
  startState = problem.getStartState()   # Get initial start state
  if problem.isGoalState(startState):  # Base case: If start is goal
      return startState    # Return starting state
  explored = []  # Initialize empty explored set
  fringe = util.Queue() # Initialize fringe as queue
  fringe.push((startState, [])) # node <- a node with STATE = problem.INITIAL-STATE
  while not fringe.isEmpty():   # While there are unexplored fringe nodes in queue
      node, sequence = fringe.pop()  # node <- pop(frontier) chooses shallowest node in frontier
      for coords, heading, steps in problem.getSuccessors(node):   # Expand chosen node
          if not coords in explored: # if child.State is not in explored set or frontier
              if problem.isGoalState(coords):    # If problem.GOAL-TEST(node.STATE)
                  return sequence + [heading]  # Return Solution(child)
              fringe.push((coords, sequence + [heading]))   # frontier <- Insert(child, frontier)
              explored.append(coords)    # Add node.State to explored
  return []   # If frontier is empty, return failure

def uniformCostSearch(problem):
  "Search the node of least total cost first. "
  "*** YOUR CODE HERE ***"
  startState = problem.getStartState()   # Get initial start state
  if problem.isGoalState(startState):  # Base case: If start is goal
      return startState    # Return starting state
  explored = [] # Initialize empty explored set
  fringe = util.PriorityQueue() # Initialize fringe as priority queue
  fringe.push((startState, []), 0) # node <- a node with STATE = problem.INITIAL-STATE, PATH-COST = 0
  while not fringe.isEmpty():   # While there are unexplored fringe nodes in priority queue
      node, sequence = fringe.pop()  # node <- POP(frontier) Chooses the lowest-cost node in frontier
      if problem.isGoalState(node): # If proble.Goal-Test(node.State)
          return sequence    # Return solution
      explored.append(node) # Add node.State to explored
      for coords, heading, steps in problem.getSuccessors(node):   # For each action in problem.Actions(node.State) do
          if not coords in explored: # If child.State is not in explored or frontier then
              bestAction = sequence + [heading]   # Calculate new sequence
              fringe.push((coords, bestAction), problem.getCostOfActions(bestAction))  # Frontier <- Insert(child,frontier)
  return []   # If frontier is empty, return failure

def nullHeuristic(state, problem=None):
  """
  A heuristic function estimates the cost from the current state to the nearest
  goal in the provided SearchProblem.  This heuristic is trivial.
  """
  return 0

def aStarSearch(problem, heuristic=nullHeuristic):
  "Search the node that has the lowest combined cost and heuristic first."
  "*** YOUR CODE HERE ***"
  startState = problem.getStartState()   # Get initial start state
  if problem.isGoalState(startState):  # Base case: If start is goal
      return startState    # Return starting state
  successors = []   # Initialize successors set
  fringe = util.PriorityQueue() # Initialize fringe as priority queue
  heur = heuristic(startState, problem)  # Get heuristic of initial state
  fringe.push((startState, []), heur)   # Add Child-Node(problem,node,action) into successors
  while not fringe.isEmpty():   # While there are unexplored fringe nodes
      node, sequence = fringe.pop()  # node <- POP(frontier)
      if problem.isGoalState(node): # If problem.GOAL-TEST(node.STATE)
          return sequence    # Return Solution(node)
      successors.append(node)   # Add node into successors set
      for coords, heading, steps in problem.getSuccessors(node):    # For each action in problem.Actions(node.State) do
          if not coords in successors:   # If new successor coordinates
              bestAction = sequence + [heading]    # Best <- the lowest f-value node
              heur = heuristic(coords, problem)  # Alternative <- the second-lowest f-value
              score = problem.getCostOfActions(bestAction) + heur   # result,best.f <- RBFS(problem,best,min(f_limit,alternative))
              fringe.push((coords, bestAction), score)   # Push best score onto fringe
  return []   # If frontier is empty, return failure



# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
