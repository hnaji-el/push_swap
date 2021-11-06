
#include "../includes/push_swap_bonus.h"

t_node	*get_new_node(char *data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = (void *)0;
	return (node);
}

int insert_at_end(char *data, t_node **tail)
{
	t_node	*node;

	node = get_new_node(data);
	if (node == NULL)
		return (-1);
	if (*tail == NULL)
	{
		node->next = node;
		*tail = node;
		return ;
	}
	node->next = (*tail)->next;
	(*tail)->next = node;
	*tail = node;
	return (0);
}

void	delete_at_beg(t_node **tail)
{
	t_node	*temp;

	if (*tail == NULL)
		return ;
	temp = (*tail)->next;
	(*tail)->next = temp->next;
	if (temp == *tail)
		*tail = (void *)0;
	free(temp);
}

int		strlen_list(t_node *tail)
{
	t_node	*head;
	int		length;

	length = 0;
	if (tail == NULL)
		return (length);
	head = tail->next;
	while (head != tail)
	{
		length++;
		head = head->next;
	}
	return (length + 1);
}

void	print_list(t_node *tail)
{
	t_node	*head;
	
	if (tail == NULL)
	{
		printf("the list is empty ...\n");
		return ;
	}
	head = tail->next;
	while (head != tail)
	{
		printf("%s\n", head->data);
		head = head->next;
	}
	printf("%s\n", head->data);
}
