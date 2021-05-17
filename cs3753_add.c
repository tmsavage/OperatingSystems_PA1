#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/uaccess.h>

asmlinkage long cs3753_add(int num1, int num2, int *result)
{
	int sum;
	printk(KERN_ALERT "Two Numbers: %d %d \n", num1, num2);
	sum =  num1 + num2;
	copy_to_user(result, &sum, sizeof(int));
	printk(KERN_ALERT "Summation of Two Numbers: %d \n", sum);
	return 0;


}
