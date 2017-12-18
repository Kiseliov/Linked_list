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
    element * temp = NULL;
    
    if(root -> link == NULL || root -> link -> link == NULL) return;
	
    while (root -> link -> link != NULL) 
	{
		p = root -> link -> link;
        do 
		{
            if (root -> link -> value > p -> value)
			{
                temp = root -> link;
				root -> link -> link = p -> link;
				root -> link = p;
				p -> link = temp;
				p = p -> link -> link;
            } else
			{
				p = p -> link;
			};
            
        } while (p != NULL);   
    	root = root -> link;
    }

}

void print_list(element* root)			////////////////// print each element
{
	if(root -> link == NULL) return;
	element* temp = root -> link;
	while(temp -> link != NULL)
	{
		cout << temp -> value << '\n';
		temp = temp -> link;
	}
	cout << temp -> value << '\n';
}

element* merge(element* root1, element* root2)
{
	element* cur_item;
	element* p1;
	element* p2;
	element* ans;
	p1 = root1;
	p2 = root2;
	if(p1->value <= p2 -> value)
	{
		cur_item = p1;
		p1 = p1->link;
	}else
	{
		cur_item = p2;
		p2 = p2->link;
	};
	ans = cur_item;
	while(p1!=NULL && p2!= NULL)
	{
		if(p1->value <= p2->value)
		{
			cur_item -> link = p1;
			cur_item = p1;
			p1 = p1 -> link;
		}else
		{
			cur_item -> link = p2;
			cur_item = p2;
			p2 = p2 -> link;
		};
	};
	if(p1!= NULL)
	{
		cur_item -> link = p1;
	}else
	{
		cur_item -> link = p2;
	};
}

struct element_of_stack
{
	int level;
	element* item;
};

void qsort_list(element* root)			//////////////////// sort for 
{
	if(root -> link == NULL) return;
	
	element_of_stack stack[32];
	int stack_pos = 0;
	element* p = root;
	while(p != NULL)
	{
		stack[stack_pos] . level = 1;
		stack[stack_pos] . item = p;
   		p = p->link;
    	stack[stack_pos] . item ->link = NULL;
    	++stack_pos;
		while(stack_pos > 1 && stack[stack_pos -1].level == stack[stack_pos - 2] . level)
		{
			stack[stack_pos - 2].item = merge(stack[stack_pos - 2].item, stack[stack_pos - 1].item);
			
			++stack[stack_pos - 2].level;
			--stack_pos;
		}  
	}
	while(stack_pos > 1)
	{
		stack[stack_pos - 2].item = merge(stack[stack_pos - 2].item, stack[stack_pos - 1].item);
		++stack[stack_pos - 2].level;
		--stack_pos;
	}
	if(stack_pos > 0)
	{
		root = stack[0].item;
	}
	
}

int main()
{
	element root;
	root.value = 0;
	root.link = NULL;
	
	add_element(1100, &root);
	add_element(2, &root);
	add_element(3, &root);
	add_element(45, &root);
	add_element(100, &root);
	add_element(100, &root);
	add_element(120, &root);
	add_element(190, &root);
	add_element(6, &root);
	sort_list(&root);
//	qsort_list(&root);
	
	print_list(&root);

	return 0;
}
