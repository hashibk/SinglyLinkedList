# Singly Linked List

This C++ program implements a template-based singly linked list, allowing various operations such as inserting elements at the start or end, searching for elements, and deleting elements. The linked list is dynamic and can handle any data type specified at compile time.

## Features

- **Insert at Start**: Add a new element to the beginning of the list.
- **Insert at End**: Append a new element to the end of the list.
- **Print List**: Display all elements in the list.
- **Search Value**: Check if a specific value exists in the list.
- **Check if Empty**: Determine if the list is empty.
- **Insert Before**: Insert a new element before a specified value in the list.
- **Delete All Occurrences**: Remove all instances of a specified value from the list.
- **Delete from Start**: Remove the first element from the list.

## Usage

1. **Create List**: Instantiate the `singlylinkedlist` object with the desired data type.
2. **Insert Elements**: Use the `insertAtStart` or `insertAtEnd` methods to add elements.
3. **Perform Operations**: Use the `print`, `search`, `isEmpty`, `insertBefore`, `deleteAll`, and `deleteAtStart` methods as needed.
4. **Interact via Menu**: The `main` function provides a menu-driven interface to interact with the linked list.

### Example

In the given code:

- The user can perform operations such as inserting values at the start or end of the list, printing the list, searching for a value, and deleting elements.
- The operations are performed based on user input, and the linked list is dynamically updated.

**Sample Menu Interaction**:
```bash
Press 1 to insert at start.
Press 2 to insert at end.
Press 3 to print.
Press 4 to search value.
Press 5 to check if empty.
Press 6 to insert value before.
Press 7 to delete all occurrences.
Press 8 to delete from start.
Press 0 to end.