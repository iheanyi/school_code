import cherrypy
import json
import math

class MovieController(object):
	data = {}


	# Get all of the moveis from teh database
	def get_movies_from_db(self, database="movies.dat"):
		openfile = open(database, 'r+')
		movie_dict = {}
		for line in openfile:

			# Split them on the '::'
			movie_info = line.rstrip('\n').split('::')
			new_movie = {'id': movie_info[0].encode('utf-8'), 'title': movie_info[1].split('(')[0].rstrip(' ').encode('utf-8'), 'year': str(movie_info[1].split('(')[1].rstrip(')')), 'description': movie_info[2].encode('utf-8')}
			movie_dict[movie_info[0]] = new_movie


		# Close the file
		openfile.close()
		return movie_dict


	# Get a single movie from the database
	def get_movie_from_db(self, index):
		new_movie = {}
		with open("movies.dat", "r+") as openfile:
			lines = openfile.readlines()
		openfile.close()

		for line in lines:
			movie_info = line.rstrip('\n').split('::')
			if(str(movie_info[0]) == str(index)):
				new_movie = {'id': str(movie_info[0]).encode('ascii'), 'title': str(movie_info[1].split('(')[0].rstrip(' ')), 'year': str(movie_info[1].split('(')[1].rstrip(')')), 'description': str(movie_info[2]).encode('ascii')}
					#return new_movie
		return new_movie

	# Define getting a single movie from the database
	def GET(self, index):
		data = {}
		data = self.get_movies_from_db('movies.dat')
		output = {'result': 'success'}

		try:
			#print "Trying to retrieve a movie with index: " + index
			#print data[str(index)]
			output['movie'] = data[str(index)]
		except Exception as ex:
			output['result'] = 'error'
			print "GET EXCEPTION RETRIEVING MOVIE: " + str(ex) + " " + index
			#output['message'] = str(ex)

		return json.dumps(output, ensure_ascii=False, encoding='utf-8')

	def PUT(self, index):
		output = {'result':'success'}

		cherrypy.response.headers['Content-Type'] = 'application/json'
		self.content = json.loads(cherrypy.request.body.read().decode('latin-1').encode('utf-8'))
		self.content['id'] = index.decode('latin-1').encode('utf-8')

		try:
			#print "Tried to Update DB with: " + index
			self.update_db(self.content, index)		
		except Exception as ex:
			print "PUT Exception: "  + str(ex) + " with index " + index
			output['result'] = 'error'
            #output['message'] = str(ex)

		return json.dumps(output)

	def DELETE(self, index):
		output = {'result': 'success'}

		try:
			#print "Trying to Delete Movie: " + index
			self.delete_from_db(index)
		except Exception as ex:
			output['result'] = 'error'
			print "DELETE EXCEPTION: " + str(ex)

		return json.dumps(output)

	def delete_from_db(self, movieid):
		with open("movies.dat", "r+") as openfile:
			lines = openfile.readlines()
		openfile.close()

		#movie_dict = {}
		with open("movies.dat", "w+") as openfile:
			for line in lines:
				movie_info = line.rstrip('\n').split('::')
				#new_movie = {'id': movie_info[0].decode('latin-1').encode('utf-8'), 'title': movie_info[1].split('(')[0].rstrip(' ').decode('latin-1').encode('utf-8'), 'year': movie_info[1].split('(')[1].rstrip(')').decode('latin-1').encode('utf-8'), 'description': movie_info[2].decode('latin-1').encode('utf-8')}
				#movie_dict[movie_info[0]] = new_movie
				#print movie_info[0], movieid

				if(movie_info[0] != movieid):
					openfile.write(line)

		openfile.close()


	def update_db(self, data, index):

		exists = False
		try:
			with open("movies.dat", "r+") as openfile:
				lines = openfile.readlines()
			openfile.close()

			with open("movies.dat", "w+") as openfile:
				for line in lines:
					movie_info = line.rstrip('\n').split('::')
					#movie_dict[movie_info[0]] = new_movie
					if(movie_info[0] == index):
						exists = True
						#print "Match found, overwriting!"
						new_movie = index + '::' + str(self.content['title']) + '(' + str(self.content['year']) + ')' + '::' + str(self.content['description']) + "\n"
						openfile.write(new_movie)
					else:
						openfile.write(line)
		except Exception as ex:
			print "Update DB Exception: " + str(ex)

		openfile.close()


		if(exists is False):
			new_movie = self.content['id'].decode('latin-1').encode('utf-8') + '::' + self.content['title'].decode('latin-1').encode('utf-8') + ' (' + self.content['year'].decode('latin-1').encode('utf-8') + ')' + '::' + self.content['description'].decode('latin-1').encode('utf-8') + "\n".encode('utf-8')

			self.add_new_movie(new_movie)

	def add_new_movie(self, data):
		try:

			with open("movies.dat", "a+") as openfile:
				#openfile = open("movies.dat", "a+")
				openfile.write(data)

				#print "Data successfully appended: " + data
				#print openfile.readlines()
				#openfile.flush()
			#print openfile.tell()
			openfile.close()
		except Exception as ex:
			print "Error Writing To File! " + str(ex)

class MoviesController(object):
	data = {}

	def get_movies_from_db(self, database="movies.dat"):
		#movie_dict = {}
		movie_array = []
		with open(database, 'r+') as openfile:
			for line in openfile:
				movie_info = line.rstrip('\n').split('::')
				new_movie = {'id': movie_info[0].decode('latin-1').encode('utf-8'), 'title': movie_info[1].split('(')[0].rstrip(' ').decode('latin-1').encode('utf-8'), 'year': movie_info[1].split('(')[1].rstrip(')').decode('latin-1').encode('utf-8'), 'description': movie_info[2].decode('latin-1').encode('utf-8')}
			#movie_dict[movie_info[0]] = {'id': movie_info[0], 'title': movie_info[1], 'description': movie_info[2]}
				movie_array.append(new_movie)

		openfile.close()

		return movie_array	

	def GET(self):
		data = self.get_movies_from_db('movies.dat')
		output = {'result': 'success' }
		output["movies"] = []

		try:
			#for m in data:
			output['movies'] = data
		except Exception as ex:
			output['result'] = 'error'
			#output['message'] = str(ex)

		return json.dumps(output)

	def POST(self):
		data = self.get_movies_from_db('movies.dat')
		output = {'result': 'success'}

		cherrypy.response.headers['Content-Type'] = 'application/json'

		self.content = json.loads(cherrypy.request.body.read().decode('latin-1').encode('utf-8'))

		#print self.content
		try:
			#print self.content
			new_movie = self.content['id'].decode('latin-1').encode('utf-8') + '::' + self.content['title'].decode('latin-1').encode('utf-8') + '(' + self.content['year'].decode('latin-1').encode('utf-8') + ')' + '::' + self.content['description'].decode('latin-1').encode('utf-8') + "\n"
			#print new_movie
			self.add_new_movie(new_movie)

				#f.write('::'.join(v for k,v in self.content.iteritems()))
		except Exception as ex:
			print "MOVIES POST ERROR" + str(ex)
			output['result'] = 'error'

		data = self.get_movies_from_db('movies.dat')
		#print "Dictionary from Data: " + str(data)
		return json.dumps(output)

	def add_new_movie(self, data):

		try:

			with open("movies.dat", "a+") as openfile:
				#openfile = open("movies.dat", "a+")
				openfile.write(data)

				#print "Data successfully appended: " + data
				#print openfile.readlines()
				openfile.flush()
			#print openfile.tell()
			openfile.close()
		except Exception as ex:
			print "Error Writing To File! " + str(ex)

	def DELETE(self):
		output = {'result': 'success'}

		try:
			open('movies.dat', 'w').close()
		except Exception as ex:
			output['result'] = 'error'

		return json.dumps(output)

class UsersController(object):
	data = {}

	def add_new_user(self, new_user): 
		try:
			with open("users.dat", "a+") as openfile:
				#openfile = open("users.dat", "a+")
				openfile.write(new_user)
			openfile.close()
		except Exception as ex:
			print "Error Writing to File: " + str(ex)

	# Get all users
	def GET(self):
		users = self.get_all_users()
		output = {'result': 'success'}
		output['users'] = []

		try:
			output["users"] = users

		except Exception as ex:
			output['result'] = 'error'
			print "Exception retrieving all users: " + str(ex)

		return json.dumps(output)

	def POST(self):
		output = {'result': 'success'}

		cherrypy.response.headers['Content-Type'] = 'application/json'

		self.content = json.loads(cherrypy.request.body.read().decode('latin-1').encode('utf-8'))

		try:
			new_user = self.content['id'].encode('utf-8') + "::" + self.content['gender'].encode('utf-8') + "::" + self.content['age'].encode('utf-8') + "::" + self.content['occupation'].encode('utf-8') + "::" + self.content['zip'].encode('utf-8') + "\n"
			self.add_new_user(new_user)
		except Exception as ex:
			output['result'] = 'error'
			print "Exception raised POST User: " + str(ex)

		return json.dumps(output)

	def DELETE(self):
		output = {'result': 'success'}

		try:
			open('users.dat', 'w').close()
		except Exception as ex:
			output['result'] = 'error'
			print "Exception Deleting All Users: " + str(ex)

		return json.dumps(output)

	def get_all_users(self):
		users = []

		for line in open("users.dat", "r+"):
			user_info = line.rstrip('\n').split('::')
			new_user = {'id': user_info[0].encode('utf-8'), 'gender': user_info[1].encode('utf-8'), 'age': user_info[2].encode('utf-8'), 'occupation': user_info[3].encode('utf-8'), 'zip': user_info[4]}
			users.append(new_user)

		return users


class UserController(object):
	data = {}

	def GET(self, index):
		output = {'result': 'success'}
		data = self.get_all_users()
		try:
			#print "Trying to retrieve user with ID: " + index
			output['user'] = data[str(index)]
		except Exception as ex:
			print "Exception Getting Single User: " + str(ex) + " at " + index
			output['result'] = 'error'

		return json.dumps(output)

	def PUT(self, index):
		output = {'result': 'success'}
		cherrypy.response.headers['Content-Type'] = 'application/json'
		self.content = json.loads(cherrypy.request.body.read())
		self.content['id'] = index.decode('latin-1').encode('utf-8')

		try:
			#print "Tried to Update User DB with: " + index
			self.update_db(self.content, index)		
		except Exception as ex:
			print "PUT Exception: "  + str(ex) + " with index " + index
			output['result'] = 'error'
            #output['message'] = str(ex)

		return json.dumps(output)

	def update_db(self, data, index):

			exists = False
			try:
				with open("users.dat", "r+") as openfile:
					lines = openfile.readlines()
				openfile.close()

				with open("users.dat", "w+") as openfile:
					for line in lines:
						user_info = line.rstrip('\n').split('::')
						#movie_dict[movie_info[0]] = new_movie
						if(user_info[0] == index):
							exists = True
							#print "Match found, overwriting!"
							new_user = index + '::' + self.content['gender'].encode('utf-8') + '::' + self.content['age'] + '::' + self.content['occupation'] + '::' + self.content['zip'] + "\n"
							openfile.write(new_user)
						else:
							openfile.write(line)
			except Exception as ex:
				print "Update DB Exception: " + str(ex)

			openfile.close()


			if(exists is False):
				new_movie = self.content['id'].decode('latin-1').encode('utf-8') + '::' + self.content['title'].decode('latin-1').encode('utf-8') + ' (' + self.content['year'].decode('latin-1').encode('utf-8') + ')' + '::' + self.content['description'].decode('latin-1').encode('utf-8') + "\n".encode('utf-8')

				self.add_new_user(new_movie)

	def add_new_user(self, new_user): 
		try:
			with open("users.dat", "a+") as openfile:
				#openfile = open("users.dat", "a+")
				openfile.write(new_user)
			openfile.close()
		except Exception as ex:
			print "Error Writing to File: " + str(ex)

	def DELETE(self, index):
		output = {'result': 'success'}

		try:
			#print "Trying to Delete User: " + index
			self.delete_from_db(index)
		except Exception as ex:
			output['result'] = 'error'
			print "DELETE EXCEPTION: " + str(ex)

		return json.dumps(output)

	
	def delete_from_db(self, userid):
		with open("users.dat", "r+") as openfile:
			lines = openfile.readlines()
		openfile.close()

		#movie_dict = {}
		with open("users.dat", "w+") as openfile:
			for line in lines:
				user_info = line.rstrip('\n').split('::')
				#new_movie = {'id': movie_info[0].decode('latin-1').encode('utf-8'), 'title': movie_info[1].split('(')[0].rstrip(' ').decode('latin-1').encode('utf-8'), 'year': movie_info[1].split('(')[1].rstrip(')').decode('latin-1').encode('utf-8'), 'description': movie_info[2].decode('latin-1').encode('utf-8')}
				#movie_dict[movie_info[0]] = new_movie
				#print user_info[0], userid

				if(user_info[0] != userid):
					openfile.write(line)
		openfile.close()

	def get_all_users(self):
		users_dict = {}

		for line in open("users.dat", "r+"):
			user_info = line.rstrip('\n').split('::')
			new_user = {'id': user_info[0].encode('utf-8'), 'gender': user_info[1].encode('utf-8'), 'age': user_info[2].encode('utf-8'), 'occupation': user_info[3].encode('utf-8'), 'zip': user_info[4]}
			users_dict[user_info[0]] = new_user

		return users_dict

class RecommendationsController(object):
	def DELETE(self):
		output = {'result': 'success' }
		try:
			open('votes.dat', 'w').close()
		except Exception as ex:
			output['result'] = 'error'
			print "Exception Deleting All Recommendations: " + str(ex)

		return json.dumps(output)

class RecommendationController(object):
	current_dict = {}

	def update_vote_db(self, data):
		with open('votes.dat', "a") as openfile:
			try:
				openfile.write(data)
				print "Added New Vote: " + data
			except Exception as ex:
				print "Exception Updating Vote DB: " + str(ex)

		openfile.close()

	def GET(self, index):

		# Make vectors based on the vote data, dot product of the vectors
		data = {}
		output = {'result': 'success'}

		try:
			data = self.get_latest_recommendation(index)
			output['movie_id'] = data
		except Exception as ex:
			print "Error Retrieving Recommendation: " + str(ex)
			output['result'] = 'error'

		return json.dumps(output)

	def PUT(self, index):
		output = {'result': 'success' }

		cherrypy.response.headers['Content-Type'] = 'application/json'
		self.content = json.loads(cherrypy.request.body.read())
		self.content['user_id'] = index.decode('latin-1').encode('utf-8')

		try:
			new_vote = self.content['user_id'] + '::' +self.content['movie_id'] + '::' + self.content['vote'] + "\n"
			self.update_vote_db(new_vote)

		except Exception as ex:
			output['result'] = 'error'
			print "Error Putting a Vote: " + str(ex)

		return json.dumps(output)

	def get_latest_recommendation(self, index):
		current_dict = {}
		vote_dict = {}
		latest = ''
		dotprod = 0
		divisor = 0

		entry_found = False
		for line in open('votes.dat', 'r'):

			#print line
			vote_data = line.rstrip('\r\n').split('::')


			# Fill up dictionary with all recommendations
			if(vote_data[0] == index):
				#print "Found Latest Vote: " + index, vote_data[1]
				current_dict[vote_data[1]] = int(vote_data[2])
				entry_found = True

			else:
				vote_dict.setdefault(vote_data[0], {})
				vote_dict[vote_data[0]].setdefault(vote_data[1], int(vote_data[2]))
				#vote_dict[vote_data[0]] = {vote_data[1]: vote_data[2]}
				#vote_dict[vote_data[0]]
				#vote_dict[vote_data[1]]

		#print entry_found

		if(entry_found):
			#vote_dict = {'user_id': index, 'movie_id': vote_data[1],'vote': vote_data[2]} 

			current_bottom_sum = 0

			#for value in current_dict.values():
				#current_bottom_sum += math.pow(value, 2)


			topsum = 0

			current_bottom_sum = 0
			bottomsum = 0
			sim = 0

			#print vote_dict

			old_sim = 0

			score_dict = {}



			for key, value in vote_dict.iteritems():
				#print "Current User is: " + key

				#print "User ID: " + key
				#print key, value
				bottomsum = 0
				topsum = 0
				current_bottom_sum = 0

				for k, v in value.iteritems():
					#for k, v in item.iteritems():
					try:
						val = current_dict.get(k)
						#print val
					except Exception as ex:
						current_dict[k] = 0
						val = 0
					#current_dict.setdefault(k, 0)

					if val == None:
						val = 0
						current_dict[k] = 0
					
					#print v
					
					topsum += val*v
					#print topsum
					bottomsum += math.pow(v, 2)
					current_bottom_sum += math.pow(val, 2)

				#print topsum
				##print bottomsum
				#print current_bottom_sum

				#old_sim = sim

				bottom_value = math.sqrt(current_bottom_sum) * math.sqrt(bottomsum)
				if (bottom_value != 0):
					sim = float(topsum/bottom_value)
				else:
					sim = 1

				topsum = 0
				current_bottom_sum = 0
				bottomsum = 0

				#print "User Sim Score: " + str(sim)

				old_sim = sim
				score_dict[key] = sim
				#print "New Maximum Sim is: " + str(sim)
				#print key
				user = key
					#sim = topsum/(math.sqrt(current_bottom_sum) * math.sqrt(bottomsum))

			#print score_dict
			
			scoreList = sorted(score_dict, key=score_dict.__getitem__, reverse=True)
			#print scoreList
			#for key, value in score_dict.itermitems():

			latest = ""

			for user in scoreList:
				if latest != "":
					break
				for key, value in vote_dict[user].iteritems():
					print "Movie ID: " + key + " VOTE: " + str(value) + " FOR USER: " + user
					print current_dict[key]
					if(value == 1 and current_dict[key] == 0):
						latest = key
						break
					else:
						latest = ''

			
			return latest
		else:
			return ''

def start_service():
	dispatcher = cherrypy.dispatch.RoutesDispatcher()

	#dispatcher.connect('data_get', '/data/:index', controller=MovieController(), action = 'GET', conditions=dict(method=['GET']))
	#dispatcher.connect('data_put', '/data/', controller=MovieController(), action = 'PUT', conditions=dict(method=['PUT']))

	dispatcher.connect('movies_get', '/movies/', controller=MoviesController(), action = 'GET', conditions=dict(method=['GET']))
	dispatcher.connect('movies_post', '/movies/', controller=MoviesController(), action= 'POST', conditions=dict(method=['POST']))
	dispatcher.connect('movies_delete', '/movies/', controller=MoviesController(), action='DELETE', conditions=dict(method=['DELETE']))

	dispatcher.connect('movie_get', '/movies/:index', controller=MovieController(), action='GET', conditions=dict(method=['GET']))
	dispatcher.connect('movie_put', '/movies/:index', controller=MovieController(), action='PUT', conditions=dict(method=['PUT']))
	dispatcher.connect('movie_delete', '/movies/:index', controller = MovieController(), action='DELETE', conditions=dict(method=['DELETE']))
	
	dispatcher.connect('users_get', '/users/', controller=UsersController(), action = 'GET', conditions=dict(method=['GET']))
	dispatcher.connect('users_post', '/users/', controller=UsersController(), action= 'POST', conditions=dict(method=['POST']))
	dispatcher.connect('users_delete', '/users/', controller=UsersController(), action='DELETE', conditions=dict(method=['DELETE']))
	
	dispatcher.connect('user_get', '/users/:index', controller=UserController(), action='GET', conditions=dict(method=['GET']))
	dispatcher.connect('user_put', '/users/:index', controller=UserController(), action='PUT', conditions=dict(method=['PUT']))
	dispatcher.connect('user_delete', '/users/:index', controller=UserController(), action='DELETE', conditions=dict(method=['DELETE']))
	
	dispatcher.connect('recommendations_delete', '/recommendations/', controller=RecommendationsController(), action='DELETE', conditions=dict(method=['DELETE']))
	
	dispatcher.connect('recommendation_get', '/recommendations/:index', controller=RecommendationController(), action='GET', conditions=dict(method=['GET']))
	dispatcher.connect('recommendation_put', '/recommendations/:index', controller=RecommendationController(), action='PUT', conditions=dict(method=['PUT']))
	
	conf = {
        	'global': {'server.socket_host': 'student00.cse.nd.edu', 'server.socket_port': 40015,},
		'/': {'request.dispatch': dispatcher,}
	}

	cherrypy.config.update(conf)
	app = cherrypy.tree.mount(None, config=conf)
	cherrypy.quickstart(app)

if __name__ == '__main__':
    start_service()

