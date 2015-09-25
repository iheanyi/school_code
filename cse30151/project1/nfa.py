import sys
import copy
from collections import defaultdict

class NFA:

	def __init__(self, nfa_filename):
		self.alphabet = set()
		self.transitions = defaultdict(lambda: defaultdict(dict))
		#self.transitions = {}
		self.states = set()
		self.start = None
		self.inits = []
		self.accepts = []
		self.finals = []
		data = open(nfa_filename, 'r')

		for line in data:
			#li = line.strip()

			# Read first line of character, determines what to do
			if line.startswith('A'):
				print line
				li = line.partition(':')[2]
				li = li.rstrip('\n').split(',')
				#alphabet_list = li
				self.alphabet = set(li)
				#print self.alphabet
				#print alphabet_list

			elif line.startswith('Q'):
				li = line.partition(':')[2]
				li = li.rstrip('\n').split(',')
				self.states = li
				#print self.states

			elif line.startswith('T'):
				li = line.partition(':')[2]
				li = li.rstrip('\n').split(',')
				#transition = (li[0], li[1], li[2])
				self.transitions[li[0]] = self.transitions.get(li[0], defaultdict(list))
				self.transitions[li[0]][li[1]] = self.transitions[li[0]].get(li[1], [])
				self.transitions[li[0]][li[1]].append(li[2])

				#transition_list[li[0]] = transition_list.get(li[0], {})
				#transition_list[li[0]][li[1]] = li[2]
				#print transition_list

				#print self.transitions

			elif line.startswith('S'):

				li = line.partition(':')[2]
				li = li.rstrip('\n').split(',')
				startState = ''.join(li)
				self.start = startState

				#print "Start: " + self.start
				#print startState
				#print "Start: "

			elif line.startswith('F'):
				li = line.partition(':')[2]
				li = li.rstrip('\n').split(',')
				#accept_list = li
				self.accepts = set(li)
				#print self.accepts
				#print accept_list

		#self.current = self.start
		self.tape_list = []

		print self.alphabet
		print self.states
		print self.transitions
		print self.accepts
		print self.start

		self.get_input()

		#assert(len(self.alphabet) > 0), "Alphabet cannot be empty!"
		#assert(len(self.states) > 0), "States cannot be empty!"

	def get_input(self):
		print "Begin tape input:"
		number = raw_input()
		number = int(number)

		assert(isinstance(number, int)), "Please enter a number."

		iterations = 0
		while(iterations != number):
			line = raw_input('')
			line = line.split(',')
			#print line
			tape = tuple(line)
			self.tape_list.append(tape)
			iterations+=1

		print self.tape_list
		self.simulate()

	def simulate(self):
		# Print first line
		#current = startState
		#print "; " + self.current
		# Current state is the start state, so we are goign to run through the entire graph
		all_states = set()
		number = 0
		total = []
		next_states = []
		total += self.get_empty_states(self.start)
		#current = self.start
		#states = []
		#current = self.start
		for trans in self.tape_list: 
			# Tuples Loop
			#current = self.start
			#current_ptr = None
			total = []
			total = self.get_empty_states(self.start)
			print '; ' + ','.join(set(total))

			for t in trans: # Loop through each element of tuple
				#total = total + self.get_empty_states(current)	

				for s in total:
					next_states += self.get_states(s, t)
					#print set(next_states)

				total = copy.copy(next_states)
				#self.inits += next_states
				next_states = []

				print t + '; ' + ','.join(set(total))

			if self.accept(total):
				print "ACCEPT"
			else:
				print "REJECT"

			print ""
				
	def get_empty_states(self, current):
		tot = []
		if not 'e' in self.transitions[current]:
			return [current]

		for transition in self.transitions[current]['e']:
			tot += [current] + self.get_empty_states(transition)


		return tot
	def check_transition(self, current, transition):
		if not transition in self.transitions[current]:
			return self.get_empty_states(current, [])

	def get_states(self, current, transition):
		total = []
		if transition in self.transitions[current]:
			total += self.transitions[current][transition]

			for state in self.transitions[current][transition]:
				if 'e' in self.transitions[state]:
					total += self.get_empty_states(state)

		return total

	def accept(self, states):
		for s in states:
			if s in self.accepts:
				return True
		return False
		#total += self.get_empty_states(current, self.transitions[state]['e'])

	#def tape(self, inputfile):

def main():
	test = NFA(sys.argv[1])
	#print test.alphabet

if __name__ == '__main__':
	main()
