#include <stdio.h>

// Constant values
#define AMOUNT 99.00
#define TAX 0.12
#define TIP1 0.15
#define TIP2 0.18
#define TIP3 0.20

// Computes for the total price
float computeTotal (int nOrders)
{
	float fTotal;
	return fTotal = nOrders * AMOUNT;
}

// Computes for the Gross Price
float computeGross(float fPrice)
{
	float gross;
	return gross = fPrice / (1 + TAX);
}

// Computes for the Tax Value
float computeTax(float fGross)
{
	float taxPrice;
	return taxPrice = fGross * TAX;
}

// Displays the divider
void displayDivider()
{
	printf("%s%s%s%s\n","----------","----------","----------","----------");
}

// Displays the date
void displayDate(int nDate)
{
	int nMonth, nDay, nYear;
	
	nMonth = nDate / 1000000;
	nDay = (nDate / 10000) % 100;
	nYear = nDate % 10000;
	printf("%d/%d/%d\n", nMonth, nDay, nYear);
}

// Computes for the tip values
void computeTips(float fGross, float* tip1, float* tip2, float* tip3)
{
	*tip1 = fGross * TIP1;
	*tip2 = fGross * TIP2;
	*tip3 = fGross * TIP3;
	printf("Tip Guide:\n");
	printf("%.0f%% = %.2f   ", TIP1*100, *tip1);
	printf("%.0f%% = %.2f   ", TIP2*100, *tip2);
	printf("%.0f%% = %.2f   ", TIP3*100, *tip3);
	printf("\n\n");
}

// Displays the header
void displayHeader()
{
	printf("%24s\n", "MyKitchen");
	printf("%29s\n", "Taft Avenue, Manila");
	printf("%26s\n", "Your Receipt");
}

// Displays the footer
void displayFooter()
{
	displayDivider();
	//print my statement centered in  a 40 character wide field
	printf("%31s\n", "Thank you very much!");
	printf("%28s\n", "See you again!");
	printf("\n\n");
}

// Prints 4 new lines
void spacingPrint()
{
	printf("\n\n\n\n");
}

// Displays the details of the receipt
void displayDetails(int nOrders, int nDate, float fPrice, float fGross, float fTax)
{
	spacingPrint();
	displayHeader();
	printf("Date: ");
	displayDate(nDate);
	displayDivider();
	printf("Number of orders: %d\n", nOrders);
	printf("Gross price: %.2f\n", fGross);
	printf("Tax: %.2f\n", fTax);
	displayDivider();
	printf("Total price: %.2f\n", fPrice);
	printf("\n\n");
	
}

// Main control
int main()
{
	int nDate, nOrders;
	float fPrice, fGross, fTax;
	float fTip1, fTip2, fTip3;
	
	printf("Date: ");
	scanf("%d", &nDate);
	
	printf("Number of orders: ");
	scanf("%d", &nOrders);
	
	// Calls the computeTotal function and assigns the returned value to fPrice
	fPrice = computeTotal(nOrders);
	// Calls the computeGross function and assigns the returned value to fGross
	fGross = computeGross(fPrice);
	// Calls the computeTax function and assigns the returned value to fTax
	fTax = computeTax(fGross);
	
	// Calls the displayDetails function
	displayDetails(nOrders, nDate, fPrice, fGross, fTax);
	// Calls the computeTips function
	computeTips(fGross, &fTip1, &fTip2, &fTip3);
	// Calls the displayFooter function
	displayFooter();


	return 0;

		
}