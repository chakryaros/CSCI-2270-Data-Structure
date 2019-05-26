node * AddNode(node *head, int key) {
	node *current = head;
	node *prev = NULL;
	while (current != NULL) {
		prev = current;
		current = current->next;
	}

	current = new node;
	current->key = key;
	current->next = NULL;
	prev->next = current;
	return head;
}