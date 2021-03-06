


#include <iostream>
#include <string>

/*int findMax(int * arr) {
	int len = sizeof(arr);
	int max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
char findMax(char * arr) {
	int len = sizeof(arr);
	char max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
double findMax(double * arr) {
	int len = sizeof(arr);
	double max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}*/

/*template<typename TN>
class myList {
public:
	TN element;
	myList * prev;
	myList * next;
	myList * first_elem;

	myList();
	myList(TN el);
	~myList();

	void changer(myList<TN> & old, myList<TN> newt) {
		old.next = newt;
	};
	/*myList<TN> *prevent() {
		return (this->prev);
	};
	myList<TN> *next2() {
		return (this->next);
	};
	void print();
	void push_back(TN new_elem);

};*/
template<typename TN>
class root {
public:
	TN element;
	root<TN> * down;
	root<TN> * right;
	root<TN> * up;
	root<TN> * using_element;
	root<TN> * cutted_element;
	int levels;
	root();
	root(TN elem);
	~root();
	int add(TN new_elem);
	int next();
	int prev();
	int at(int i);
	int print_brothers();
	int print_using_element();
	int cut_elem(int pos);
	int copy_elem(int pos);
	int paste_elem();
	int delete_all_elem(root<TN> * elem);
	int delete_elem(int pos);
	int add_son(TN new_elem);
	int add_brother(TN new_elem, int level);
	void print(root<TN> * elem);

};

int main()
{
	/*int len;
	std::cin >> len;
	int* arr_int = new int[len];
	for (int i = 0; i < len; i++) {
		std::cin >> arr_int[i];
	}
	std::cout << findMax(arr_int) << std::endl;
	std::cin >> len;
	char* arr_char = new char[len];
	for (int i = 0; i < len; i++) {
		std::cin >> arr_char[i];
	}
	std::cout << findMax(arr_char) << std::endl;
	std::cin >> len;
	double* arr_double = new double [len];
	for (int i = 0; i < len; i++) {
		std::cin >> arr_double[i];
	}
	std::cout << findMax(arr_double) << std::endl;*/
	/*myList<int>list(1);
	list.push_back(2);
	list.push_back(3);
	list.print();
	std::string input;
	std::cin >> input;
	root<std::string> roots(input);
	std::cin >> input;
	roots.add_son(input);
	std::cin >> input;
	roots.add_son(input);
	std::cin >> input;
	roots.add_brother(input, 1);
	std::cin >> input;
	roots.add_brother(input, 2);
	roots.print();*/
	std::cout << "Commands that you can use:\ndir - to watch files in this directory\ncd + point - to change directory\n";
	std::cout << "cd -1 - to go up\nadd - to add new file in this directory\nexit - to stop the programm\n";
	std::cout << "delete + point - to delete element\ncopy - to copy element\ncut + point to cut the elem\n";
	std::cout << "paste - to paste the elem\n";
	std::cout << "Write a root: ";
	std::string str;
	int point;
	std::cin >> str;
	root<std::string> tree(str);
	std::cout << "Now you are in " << tree.element << '>';
	bool not_exit = true;
	while (not_exit) {
		std::cin >> str;
		if (str == "exit") {
			break;
		}
		if (str == "cd") {
			//std::cout << "Choose a point: ";
			std::cin >> point;
			if (point < -1 || point == 0) {
				std::cout << "Error! Wrong point!\n";
				tree.print_using_element();
				continue;
			}
			if (point == -1) {
				tree.prev();
				tree.print_using_element();
				continue;
			}
			else {
				tree.next();
				tree.at(point);
				tree.print_using_element();
				continue;
			}
		}
	
		if (str == "dir") {
			tree.print_brothers();
			tree.print_using_element();
			continue;
		}
		if (str == "add") {
			std::cin >> str;
			tree.add(str);
			tree.print_using_element();
			continue;
		}
		if (str == "delete") {
			std::cin >> point;
			tree.delete_elem(point);
			tree.print_using_element();
			continue;
		}
		if (str == "cut") {
			std::cin >> point;
			tree.cut_elem(point);
			tree.print_using_element();
			continue;
		}
		if (str == "paste") {
			tree.paste_elem();
			tree.print_using_element();
			continue;
		}
		if (str == "copy") {
			std::cin >> point;
			tree.copy_elem(point);
			tree.print_using_element();
			continue;
		}
		if (str == "print") {
			root<std::string> * tree_ptr = new root<std::string>;
			tree_ptr = &tree;
			tree.print(tree_ptr);
			continue;
		}
		std::cout << "There is no command \"" << str << "\"\n";
		tree.print_using_element();
		continue;
	}
	return 0;
}

/*template<typename TN>
myList<TN>::myList()
{
	prev = NULL;
	next = NULL;
}

template<typename TN>
myList<TN>::myList(TN el)
{
	prev = NULL;
	next = NULL;
	element = el;
}

template<typename TN>
myList<TN>::~myList()
{
	if (prev != NULL) {
		delete prev;
	}
	if (next != NULL) {
		delete next;
	}
}

template<typename TN>
void myList<TN>::print()
{
	myList<TN> *temp = new myList<TN>;
	temp = this;
	while (temp->prev != NULL)
	{
		*this = *(temp->prev);
		temp = this;
	}
	while (temp->next != NULL)
	{
		std::cout << temp->element << '\t';
		temp = temp->next;
		//*this = *temp;
	}
	std::cout << temp->element << '\t';
}

template<typename TN>
void myList<TN>::push_back(TN new_elem)
{
	myList<TN> *tmp = new myList<TN>;//указатель на новый элемент
	myList<TN> *tmp1 = new myList<TN>;//указатель на текущий элемент
	tmp1 = this;// создаём копию указателя
	tmp1->next = tmp;//изменяем указатель на следующий элемент для текущего элмента
	tmp->element = new_elem;
	tmp->prev = tmp1;//this
	tmp->next = NULL;
	//tmp1->next = tmp;//изменяем указатель на следующий элемент для текущего элмента

	this->element = tmp->element;
	this->prev = tmp1;
	this->next = NULL;//TMP


}




/*template<typename TN>
root<TN> root<TN>::operator=(root & new_element)
{
	this->element = new_element.element;
	this->down = new_element.down;
	this->right = new_element.right;
	this->head = new_element.head;
	return *this;
}*/

template<typename TN>
root<TN>::root()
{
	right = NULL;
	down = NULL;
	up = NULL;
	using_element = NULL;
	cutted_element = NULL;
}

template<typename TN>
root<TN>::root(TN elem)
{
	right = NULL;
	down = NULL;
	up = NULL;
	cutted_element = NULL;
	using_element = this;
	element = elem;
}

template<typename TN>
root<TN>::~root()
{
	/*
	if (down != NULL) {
		delete down;
	}

	if (right != NULL) {
		delete right;
	}
	if (up != NULL) {
		delete up;
	}
	if (using_element != NULL) {
		delete using_element;
	}*/
}

template<typename TN>
int root<TN>::add(TN new_elem)
{
	root<TN> * head_ptr = new root<TN>;
	root<TN> * tmp_ptr = new root<TN>;
	if (this->using_element == NULL) {
		head_ptr = this;
		this->using_element = head_ptr;
	}
	else {

		head_ptr = this->using_element;
	}
	if (head_ptr->down == NULL) {
		head_ptr->down = tmp_ptr;
		tmp_ptr->up = head_ptr;
		tmp_ptr->element = new_elem;
	}
	else {
		root<TN> * tmp_down = new root<TN>;
		tmp_down = head_ptr->down;
		while (tmp_down->right != NULL) {
			tmp_down = tmp_down->right;
		}
		tmp_down->right = tmp_ptr;
		tmp_ptr->up = head_ptr;
		tmp_ptr->element = new_elem;
	}
	return 0;
}

template<typename TN>
int root<TN>::next()
{
	if (this->using_element == NULL) {
		if (this->down == NULL) {
			std::cout << "Error! Out of range.\n";
			return -1;
		}
		this->using_element = this->down;
	}
	else
	{
		if (this->using_element->down == NULL) {
			std::cout << "Error! Out of range.\n";
			return -1;
		}
		this->using_element = this->using_element->down;
	}
	return 0;
}

template<typename TN>
int root<TN>::prev()
{
	if (this->using_element == NULL) {
		if (this->up == NULL) {
			std::cout << "Error! Out of range.\n";
			return -1;
		}
		this->using_element = this->up;
	}
	else
	{
		if (this->using_element->up == NULL) {
			std::cout << "Error! Out of range.\n";
			return -1;
		}
		this->using_element = this->using_element->up;
	}

	return 0;
}

template<typename TN>
int root<TN>::at(int i)
{
	for (int j = 1; j < i; j++) {
		if (this->using_element->right == NULL) {
			std::cout << "Error! Out of range.\n";
			return -1;
		}
		this->using_element = this->using_element->right;
	}
	return 0;
}

template<typename TN>
int root<TN>::print_brothers()
{
	root<TN> * tmp_ptr = new root<TN>;
	int i = 0;
	if (this->using_element->down == NULL) {
		std::cout << "There is no elements.\n";
		return -1;
	}
	tmp_ptr = this->using_element->down;
	while (tmp_ptr->right != NULL) {
		i++;
		std::cout << i << '.' << tmp_ptr->element << ' ';
		if (double(i) / 3 == i / 3) {
			std::cout << '\n';
		}
		tmp_ptr = tmp_ptr->right;
	}
	i++;
	std::cout << i << '.' << tmp_ptr->element << std::endl;
	return 0;
}

template<typename TN>
int root<TN>::print_using_element()
{
	std::cout << "Now, you are in " << this->using_element->element << '>';
	return 0;
}

template<typename TN>
int root<TN>::cut_elem(int pos)
{
	if (pos <= 0) {
		std::cout << "Error! Out of range.\n";
		return -1;
	}
	if (pos == 1) {
		root<TN> * head_ptr = new root<TN>;
		root<TN> * cutting_ptr = new root<TN>;
		head_ptr = this->using_element;
		if (head_ptr->down == NULL) {
			std::cout << "Error! There is no such element!\n";
			return -1;
		}
		cutting_ptr = head_ptr->down;
		if (cutting_ptr->right != NULL) {
			root<TN> * tmp_ptr = new root<TN>;
			tmp_ptr = cutting_ptr->right;
			head_ptr->down = tmp_ptr;
		}
		else {
			head_ptr->down = NULL;
		}
		this->cutted_element = cutting_ptr;
		return 0;
	}
	root<TN> * head_ptr = new root<TN>;
	root<TN> * cutting_ptr = new root<TN>;
	root<TN> * tmp_ptr = new root<TN>;
	if (this->using_element->down == NULL) {
		std::cout << "Error! There is no such element!\n";
		return -1;
	}
	head_ptr = this->using_element->down;
	if (head_ptr->right == NULL) {
		std::cout << "Error! There is no such element!\n";
		return -1;
	}
	cutting_ptr = head_ptr->right;
	tmp_ptr = head_ptr;
	for (int i = 2; i < pos; i++) {
		if (cutting_ptr->right = NULL) {
			std::cout << "Error! There is no such element!\n";
			return -1;
		}
		tmp_ptr = cutting_ptr;
		cutting_ptr = cutting_ptr->right;
	}
	if (cutting_ptr->right != NULL) {
		tmp_ptr->right = cutting_ptr->right;
	}
	else {
		tmp_ptr->right = NULL;
	}
	this->cutted_element = cutting_ptr;
	return 0;
}

template<typename TN>
int root<TN>::copy_elem(int pos)
{
	if (pos <= 0) {
		std::cout << "Error! Out of range.\n";
		return -1;
	}
	if (pos == 1) {
		this->cutted_element = this->using_element->down;
	}
	else {
		root<TN> * copy = new root<TN>;
		copy = this->using_element->down;
		for(int i = 1; i < pos; i++){
			if (copy->right == NULL) {
				std::cout << "There is no such element.\n";
				return -1;
			}
			copy = copy->right;
		}
		this->cutted_element = copy;
	}
	return 0;
}

template<typename TN>
int root<TN>::paste_elem()
{
	//root<TN> * pasting_elem = new root<TN>;
	if (this->cutted_element == NULL) {
		std::cout << "You are not cutted any element.\n";
		return -1;
	}
	if (this->using_element->down == NULL) {
		this->using_element->down = this->cutted_element;
	}
	else {
		root<TN> * down_elem = new root<TN>;
		down_elem = this->using_element->down;
		while (down_elem->right != NULL) {
			down_elem = down_elem->right;
		}
		down_elem->right = this->cutted_element;
	}
	this->cutted_element = NULL;
	return 0;
}

template<typename TN>
int root<TN>::delete_all_elem(root<TN>* elem)
{
	if (elem->right != NULL) {
		delete_all_elem(elem->right);
	}
	if (elem->down != NULL) {
		delete_all_elem(elem->down);
	}
	delete elem;
	elem = nullptr;
	return 0;
}

template<typename TN>
int root<TN>::delete_elem(int pos)
{
	if (pos <= 0) {
		std::cout << "Error! Out of range.\n";
		return -1;
	}
	if (pos == 1) {
		root<TN> * head_ptr = new root<TN>;
		root<TN> * deleting_ptr = new root<TN>;
		head_ptr = this->using_element;
		if (head_ptr->down == NULL) {
			std::cout << "Error! There is no such element!\n";
			return -1;
		}
		deleting_ptr = head_ptr->down;
		if (deleting_ptr->right != NULL) {
			root<TN> * tmp_ptr = new root<TN>;
			tmp_ptr = deleting_ptr->right;
			head_ptr->down = tmp_ptr;
		}
		else {
			head_ptr->down = NULL;
		}
		if (deleting_ptr->down != NULL) {
			delete_all_elem(deleting_ptr->down);
		}
		delete deleting_ptr;
		deleting_ptr = nullptr;
		return 0;
	}
	root<TN> * head_ptr = new root<TN>;
	root<TN> * deleting_ptr = new root<TN>;
	root<TN> * tmp_ptr = new root<TN>;
	if (this->using_element->down == NULL) {
		std::cout << "Error! There is no such element!\n";
		return -1;
	}
	head_ptr = this->using_element->down;
	if (head_ptr->right == NULL) {
		std::cout << "Error! There is no such element!\n";
		return -1;
	}
	deleting_ptr = head_ptr->right;
	tmp_ptr = head_ptr;
	for (int i = 2; i < pos; i++) {
		if (deleting_ptr->right = NULL) {
			std::cout << "Error! There is no such element!\n";
			return -1;
		}
		tmp_ptr = deleting_ptr;
		deleting_ptr = deleting_ptr->right;
	}
	if (deleting_ptr->right != NULL) {
		tmp_ptr->right = deleting_ptr->right;
	}
	else {
		tmp_ptr->right = NULL;
	}
	if (deleting_ptr->down != NULL) {
		delete_all_elem(deleting_ptr->down);
	}
	delete deleting_ptr;
	deleting_ptr = nullptr;
	return 0;
}





template<typename TN>
int root<TN>::add_son(TN new_elem)
{
	root <TN> * head_ptr = new root<TN>;
	levels++;
	head_ptr = this;
	while (head_ptr->down != NULL) {
		head_ptr = head_ptr->down;
	}
	root <TN> * tmp_ptr = new root<TN>;
	head_ptr->down = new root<TN>;
	head_ptr->down = tmp_ptr;
	tmp_ptr->element = new_elem;
	tmp_ptr->down = NULL;
	tmp_ptr->right = NULL;
	return 0;
}

template<typename TN>
int root<TN>::add_brother(TN new_elem, int level)
{
	if (level > levels) {
		return -1;
	}
	root <TN> * head_ptr = new root<TN>;
	head_ptr = this;
	for (int i = 0; i < level; i++) {
		head_ptr = head_ptr->down;
	}
	while (head_ptr->right != NULL) {
		head_ptr = head_ptr->right;
	}
	root <TN> * tmp_ptr = new root<TN>;
	head_ptr->right = new root<TN>;
	head_ptr->right = tmp_ptr;
	tmp_ptr->element = new_elem;
	tmp_ptr->down = NULL;
	tmp_ptr->right = NULL;
	return 0;
}

template<typename TN>
void root<TN>::print(root<TN> * elem)
{
	root<TN> * tmp_ptr = new root<TN>;
	tmp_ptr = this->using_element;
	std::cout << tmp_ptr->element;
	if (tmp_ptr->right != NULL) {
		std::cout << "->";
		this->using_element = tmp_ptr->right;
		print(this->using_element);
	}
	if (tmp_ptr->down != NULL) {
		std::cout << '\n' << '|';
		this->using_element = tmp_ptr->down;
		print(this->using_element);
	}
}

/*template<typename TN>
void root<TN>::print()
{
	root <TN> * head_ptr = new root<TN>;
	root <TN> * tmp = new root<TN>;
	head_ptr = this;
	while (head_ptr->down != NULL)
	{
		std::cout << head_ptr->element;
		tmp = head_ptr;
		while (tmp->right != NULL)
		{
			tmp = tmp->right;
			std::cout << " - " << tmp->element;
		}
		std::cout << std::endl << " |" << std::endl;
		head_ptr = head_ptr->down;
		
	}
	std::cout << head_ptr->element;
	tmp = head_ptr;
	while (tmp->right != NULL)
	{
		tmp = tmp->right;
		std::cout << " - " << tmp->element;
	}
}*/

 