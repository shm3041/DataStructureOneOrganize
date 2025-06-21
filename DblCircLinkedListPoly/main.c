#include <stdio.h>
#include <stdlib.h>

#include "DoubleCircularLinkedList.h"

void addPoly(NodeType* AH, NodeType* BH, NodeType* CH) {
	NodeType* a = AH->rLink;
	NodeType* b = BH->rLink;

	while (a != AH && b != BH) {
		if (a->data.expo > b->data.expo) {
			insertLastDClinkedList(CH, a->data);
			a = a->rLink;
		}
		else if (a->data.expo < b->data.expo) {
			insertLastDClinkedList(CH, b->data);
			b = b->rLink;
		}
		else {
			insertLastDClinkedList(CH, (elementType) { (a->data.coef + b->data.coef), a->data.expo });
			a = a->rLink;
			b = b->rLink;
		}
	}
	while (a != AH) {
		insertLastDClinkedList(CH, a->data);
		a = a->rLink;
	}
	while (b != BH) {
		insertLastDClinkedList(CH, b->data);
		b = b->rLink;
	}
}

int main() {
	NodeType* A, * B, * C;
	A = createDClinkedList();
	B = createDClinkedList();
	C = createDClinkedList();

	insertLastDClinkedList(A, (elementType) { 4, 3 });
	insertLastDClinkedList(A, (elementType) { 3, 2 });
	insertLastDClinkedList(A, (elementType) { 5, 1 });
	printf("Polynomial A(x)\n");
	printDClinkedList(A);

	insertLastDClinkedList(B, (elementType) { 3, 4 });
	insertLastDClinkedList(B, (elementType) { 1, 3 });
	insertLastDClinkedList(B, (elementType) { 2, 1 });
	insertLastDClinkedList(B, (elementType) { 1, 0 });
	printf("Polynomial B(x)\n");
	printDClinkedList(B);

	addPoly(A, B, C);
	printf("Polynomial C(x)\n");
	printDClinkedList(C);

	distroyDClinkedList(A);
	distroyDClinkedList(B);
	distroyDClinkedList(C);
	return 0;
}