class ListNode:
    def __init__(self, val):
        self.value = val
        self.next = None


class SingleList:
    def __init__(self):
        self.head = None
        self.tail = None

    def add(self, val):
        """
        Add an element to the list
        """
        if self.head is None:
            self.head = ListNode(val)
            self.tail = self.head
        else:
            temp = ListNode(val)
            self.tail.next = temp
            self.tail = temp

    def find(self, val):
        """
        Find an element in the list
        and returns the pointer to the element
        """
        pointer = self.head

        while pointer:
            if pointer.value == val:
                return pointer
            pointer = pointer.next

    def remove(self, val):
        """
        Remove an element from the list
        """
        prev = None
        current = self.head

        while current:
            if current.value == val:
                if prev is None:
                    self.head = current.next
                else:
                    prev.next = current.next
                return val
