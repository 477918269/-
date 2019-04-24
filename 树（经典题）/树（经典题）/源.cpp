void AllPath(CSTree T, stack<ElemType> *S1) {
	//stack<ElemType> S1;

	while (T != NULL) {
		S1->push(T->data);
		if (T->firstchild == NULL) {
			stack<ElemType> S2;
			S2 = (*S1);
			while (!S2.empty()) {
				printf("%c\n", S2.top());
				S2.pop();
			}
		}
		else {
			AllPath(T->firstchild, S1);
		}
		S1->pop();
		T = T->nextsibling;
	}
}
