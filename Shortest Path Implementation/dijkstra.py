
#Nirdesh Bhandari 
#Class : Computer Networks 

#  My Python Implementation of Dijkstra's Shortest path algorithm for given input files.

input_file = open('two.net')


      
with input_file as f: 

#Reading the input file and getting the data as three touples

    input_data = []
    for line in f:
        line = line.split() 
        if line:            
            line = [int(i) for i in line]
            input_data.append(line)



all_nodes = []       #Getting a list of all the nodes we have. 

for x in input_data:

	if x[0] not in all_nodes:
		all_nodes.append(x[0])
	if x[1] not in all_nodes:
		all_nodes.append(x[1])

print ("All the nodes we have:", all_nodes)
print('')
print('')

node_connections = {}
connection_costs = {}	
								#Getting conections on each node 

for x in all_nodes:
	temp_visitable =[x]        #Node is visitable by itself for zero cost. 
	temp_cost = [0]				#Also getting the cost to make work later easier 
	for connection in input_data: 

		 #Making sure weather node is source/destination doesn't matter. 

		if connection[0] == x:  
			temp_visitable.append(connection[1])
			temp_cost.append(connection[2])
		if connection[1] == x:
			temp_visitable.append(connection[0])
			temp_cost.append(connection[2])
	node_connections[x] = temp_visitable
	connection_costs[x] = temp_cost

			#printing the connections 

print("All nodes and their Connections and costs : " )
for k, v in node_connections.items():
	print(k,v,connection_costs.get(k, None) )
	
print('')
print('')


############################################################################

for source in all_nodes:     #do this for all discovered nodes

	m = source
	already_discovered = {}
    
    										#(Destination node, go to this node )

	already_discovered[source] = (source,0)
	min_cost_total = 0
	already_visited = [source]
	node = source
	least_cost = None
												#make sure we go to each node and check 

	while already_visited.__len__() < all_nodes.__len__():  
	

		connections = node_connections.get(node, None)  		#Get connecting edges
		cost = connection_costs.get(node, None) 			#Get respective costs 
	
		for index,value in  enumerate(cost): 
			if value != 0: 

				compare_node = connections[index]

																#for newly discovered node.

				if compare_node not in already_discovered.keys(): 
					cost_to_get_there = value + min_cost_total					
					already_discovered[compare_node] = (node, cost_to_get_there)
																			
				low_cost = already_discovered.get(compare_node,None)    #check if lower cost connections exist from this point.
				previous_cost = low_cost[1] 
				new_value = value + min_cost_total	
				
				if new_value <= previous_cost: 

					already_discovered.pop(compare_node)				
					already_discovered[compare_node] = (node,new_value) 	#Add new found path to dictionary.



				new_value = 0 


		for key, path in already_discovered.items():  

			if key not in already_visited :      #make sure node hasn't been visited before 
				if least_cost == None:      #must visit a node.
					least_cost = path[1]
					visit = key						
				if path[1] < least_cost:	#Find the next smallest cost path to visit.			
					least_cost = path[1]
					visit = key

		node = visit                           #vist lowest cost node in the table.
		min_cost_total = least_cost
		already_visited.append(node)
		least_cost = None

        

	final_route = already_discovered     # Now lets make our results slightly more workable     

	for one, two in final_route.items(): 
		send_to = two[0]
	
		if send_to == source:    #if destination is source, send to route.
			route = one
	
		else:
			while send_to != source :   #while destination is not source 
		
				go_to = already_discovered.get(send_to,None)
				route = send_to
				send_to = go_to[0]
			

		print("Source=" , source , "... Destination= ", one , "...Route= ", route, "..Cost= ", two[1])
	
	print('')
	print('')



