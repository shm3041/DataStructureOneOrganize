#include <stdio.h>

int sum(int num1, int num2); //µ¡¼À ÇÔ¼ö
int sub(int num1, int num2); //»¬¼À ÇÔ¼ö
int mul(int num1, int num2); //°ö¼À ÇÔ¼ö
float div(int num1, int num2); //³ª´°¼À ÇÔ¼ö

int main() {
	int num1, num2;

	//Á¤¼ö 2°³ ÀÔ·Â¹Ş±â
	printf("Ã¹ ¹øÂ° ¾çÀÇ Á¤¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
	scanf_s("%d", &num1);
	printf("µÎ ¹øÂ° ¾çÀÇ Á¤¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
	scanf_s("%d", &num2);

	//»çÄ¢¿¬»ê ÈÄ °á°ú Ãâ·Â
	printf("µ¡¼À: %d\n", sum(num1, num2));
	printf("»¬¼À: %d\n", sub(num1, num2));
	printf("°ö¼À: %d\n", mul(num1, num2));
	printf("³ª´°¼À: %.2f\n", div(num1, num2));
	
	return 0;
}

//µ¡¼À
int sum(int num1, int num2) {
	return num1 + num2;
}

//»¬¼À
int sub(int num1, int num2) {
	return num1 - num2;
}

//°ö¼À
int mul(int num1, int num2) {
	return num1 * num2;
}

//³ª´°¼À
float div(int num1, int num2) {
	return (float)num1 / (float)num2;
}