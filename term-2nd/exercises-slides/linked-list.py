class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def __repr__(self):
        info = ""
        temp = self.head

        while temp is not None:
            info += str(temp.data) + "-> "
            temp = temp.next
        info += "None"
        return info

    def addToFront(self, data):
        temp = Node(data)
        temp.next = self.head
        self.head = temp

    def addToTail(self, data):
        last = self.head

        if self.head is None:
            self.head = Node(data)
            return

        while last.next is not None:
            last = last.next
        last.next = Node(data)

    def removeFirstNode(self):
        if self.head is None:
            return

        temp = self.head.next
        self.head = temp

    def removeLastNode(self):
        temp = self.head

        if self.head is None:
            return

        if self.head.next is None:
            self.head = None
            return

        while temp.next.next is not None:
            temp = temp.next
        temp.next = None

    def removeByNode(self, data):
        temp = self.head

        if self.head is None:
            return
        
        if self.head.data == data and self.head.next is None:
            self.head = None
            return

        while temp.next is not None:
            if temp.next.data == data:
                temp.next = temp.next.next
                continue
            temp = temp.next

    def removeAfterValue(self, data):
        temp = self.head

        if self.head is None or self.head.next is None:
            return
        
        while temp.next is not None:
            if temp.data == data:
                temp.next = temp.next.next

                if temp is None:
                    return
            temp = temp.next

    def addByValue(self, data, pos):
        newNode = Node(data)
        temp = self.head
        count = 0

        if pos == 0:
            self.AddToFront(data)
            return

        if self.head is None:
            return

        while temp.next is not None:
            if count == pos - 1:
                next = temp.next
                newNode.next = next
                temp.next = newNode
                break
            count += 1
            temp = temp.next

        if count == pos - 1:
            temp.next = newNode

        else:
            print("The position exceed the amount of nodes in the linked list")
            return
        return
    
    def reverse(self):
        prev = None
        current = self.head

        while(current is not None):
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev

    def removeBefore(self, target):
        if self.head is None or self.head.next is None:
            return

        if self.head.next.data == target:
            self.head = self.head.next 

        temp = self.head

        while temp is not None and temp.next is not None and temp.next.next is not None:
            if temp.next.next.data == target:
                temp.next = temp.next.next
            temp = temp.next


