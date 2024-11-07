from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def bfs(root):
    if root is None:
        return

    queue = deque([root])

    while queue:
        current_node = queue.popleft()
        print(current_node.data, end=" ")

        if current_node.left is not None:
            queue.append(current_node.left)

        if current_node.right is not None:
            queue.append(current_node.right)

# Creating the tree
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

# Perform BFS
print("BFS Traversal: ", end="")
bfs(root)
print()
