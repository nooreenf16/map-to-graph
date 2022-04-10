from collections import defaultdict

class Node_Distance :

    def __init__(self, name : int, dist : int) :
        self.name = name
        self.dist = dist

class Graph :

    def __init__ (self, node_count : int) :
        # Store the adjacency list as a dictionary
        # The default dictionary would create an empty list as a default (value) 
        # for the nonexistent keys.
        self.adjlist = defaultdict(list)
        self.node_count = node_count

    def Add_Into_Adjlist (self, src : int, node_dist : Node_Distance(int,int)) :
        self.adjlist[src].append(node_dist)

    def Dijkstras_Shortest_Path (self, source : int) :

        # Initialize the distance of all the nodes from the source node to infinity
        distance = [999999999999] * self.node_count
        # Distance of source node to itself is 0
        distance[source] = 0

        # Create a dictionary of { node, distance_from_source }
        dict_node_length = {source: 0}

        while dict_node_length :

            # Get the key for the smallest value in the dictionary
            # i.e Get the node with the shortest distance from the source
            current_source_node = min(dict_node_length, key = lambda k: dict_node_length[k])
            del dict_node_length[current_source_node]

            for node_dist in self.adjlist[current_source_node] :
                adjnode = node_dist.name
                length_to_adjnode = node_dist.dist

                # Edge relaxation
                if distance[adjnode] > distance[current_source_node] + length_to_adjnode :
                    distance[adjnode] = distance[current_source_node] + length_to_adjnode
                    dict_node_length[adjnode] = distance[adjnode]

        for i in range(self.node_count) :
            print("Source Node ("+str(source)+")  -> Destination Node(" + str(i) + ")  : " + str(distance[i]))

def main() :

    g = Graph(6)

    # Node 0: <1,5> <2,1> <3,4>
    g.Add_Into_Adjlist(1, Node_Distance(0, 1))

    # Node 1: <0,5> <2,3> <4,8> 
    g.Add_Into_Adjlist(1, Node_Distance(1, 2))

    # Node 2: <0,1> <1,3> <3,2> <4,1>
    g.Add_Into_Adjlist(1, Node_Distance(2, 3))

    # Node 3: <0,4> <2,2> <4,2> <5,1>
    g.Add_Into_Adjlist(1, Node_Distance(3, 4))

    # Node 4: <1,8> <2,1> <3,2> <5,3>
    g.Add_Into_Adjlist(1, Node_Distance(5, 4))

    # Node 5: <3,1> <4,3> 
    g.Add_Into_Adjlist(1, Node_Distance(6, 5))

    g.Dijkstras_Shortest_Path(0)
    print("\n")
    #g.Dijkstras_Shortest_Path(5)

if __name__ == "__main__" :
   main()