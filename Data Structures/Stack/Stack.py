# stack using a Linked List

# Push - adds data to the “top” of the stack
# Pop - returns and removes data from the “top” of the stack
# Peek - returns data from the “top” of the stack without removing it
# Last in, First Out
# What happens to peek() or pop() when our stack is empty?
# How do we stop from push()ing to a stack that has already reached its limit?


class Node:
    def __init__(self, value, next_node=None):
        self.value = value
        self.next_node = next_node

    def set_next_node(self, next_node):
        self.next_node = next_node

    def get_next_node(self):
        return self.next_node

    def get_value(self):
        return self.value


class Stack:
    def __init__(self, limit=1000):
        self.top_item = None
        self.limit = limit
        self.size = 0

    def has_space(self):
        return self.limit > self.size

    def is_empty(self):
        return self.size == 0

    def push(self, value):
        if self.has_space():
            item = Node(value)
            item.set_next_node(self.top_item)
            self.top_item = item
            self.size += 1
        else:
            print("All out of space!")

    def pop(self):
        if(self.size > 0):
            item_to_remove = self.top_item
            self.top_item = item_to_remove.get_next_node()
            # Decrementing the stack size :
            self.size -= 1
            return item_to_remove.get_value()
        else:
            print("The stack is empty")

    def peek(self):
        if(not self.is_empty()):
            return self.top_item.get_value()
        else:
            print("The stack is empty")


items = Stack()

items.push(30)
items.push(40)

print(items.peek())

items.pop()
print(items.peek())
