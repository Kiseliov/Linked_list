#include <iostream>

using namespace std;

struct element
{
	int value;
	element* link;
};

void add_element(int value, element* root)
{
	element* temp = root;
	while(temp -> link != NULL)
	{
		temp = temp -> link;
	}
	element* new_element;
	new_element = (element*)malloc(sizeof(element));
	temp -> link = new_element;
	new_element -> link = NULL;
	new_element -> value = value;
}

int get_element(int number, element root)		////////////////////// give out value of element with number "number" 
{
	element* temp = root.link;
	while(number != 0)
	{
		temp = temp -> link;
		--number;
	}
	return temp -> value;
}

void change_element(int number, element* root, int value) //////////// change value of element with number "number" to value "value"
{
	element* temp = root -> link;
	while(number != 0)
	{
		temp = temp -> link;
		--number;
	}
	temp -> value = value;
	
}

void del_element(int number, element* root)	///////////////////////// deleting element with number "number"
{	
	element* temp = root -> link;
	element* prev;
	prev = temp;
	while(number != 0)
	{
		prev = temp;
		temp = temp -> link;
		--number;
	}
	
	if (root != temp) {
		prev -> link = temp -> link;	
	} else {
		temp -> link = temp -> link -> link; 
	}
}

void sort_list(element* root)		////////////////////// sorting list
{
    element * p = NULL;
    while (root->link != NULL) 
	{
        p = root->link;
        do 
		{
            if (p->value < root->value)
			{
                int temp = p->value;
                p->value = root->value;
                root->value = temp;
            }    
            p = p->link;
        } while (p != NULL);   
    	root = root->link;
    }

}

void print_list(element* root)			////////////////// print each ele
{
	if(root -> link == NULL) return;
	element* temp = root -> link;
	cout << temp -> value << '\n';
	while(temp -> link != NULL)
	{
		temp = temp -> link;
		cout << temp -> value << '\n';
	}
}

int main()
{
	element root;
	root.value = 0;
	root.link = NULL;
	
	print_list(&root);
	
	add_element(1100, &root);
	add_element(2, &root);
	add_element(3, &root);
	add_element(5, &root);
	add_element(45, &root);
	
	del_element(2, &root);
	
	change_element(2, &root, 4);
	
	sort_list(&root);
	
	print_list(&root);

	return 0;
}
