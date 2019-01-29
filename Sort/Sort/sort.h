typedef int ElemType;



void insertSort(ElemType a[],int n,int (* compare)(ElemType,ElemType));
void selectSort(ElemType a[],int n,int (* compare)(ElemType,ElemType));
void bubbleSort(ElemType a[],int n,int (* compare)(ElemType,ElemType));
void mergeSort(ElemType a[],int n);
void msort(ElemType a[],ElemType b[],int s,int t);
void merge(ElemType a[],ElemType b[],int s,int m,int n);
int compare(ElemType a,ElemType b);
void swap(ElemType a[],int i,int j);
void quickSort(ElemType a[],int length);
void qsort(ElemType a[],int low,int high);
int partition(ElemType a[],int low,int high);
void printArray(int a[],int n);


void printArray(int a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf_s("%d  ",a[i]);
	}
	printf_s("\n\n");
}



//��a<b���򷵻�true
//���򷵻�false
int compare(ElemType a,ElemType b)
{
	return a < b;
}



//����Ԫ��a��b
void swap(ElemType a[],int i,int j)
{
	ElemType tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}



void quickSort(ElemType a[],int length)
{
	qsort(a,0,length-1);
}



void qsort(ElemType a[],int low,int high)
{
	//ע��ݹ��������
	if (low < high)
	{
		int pivotLoc = partition(a,low,high);
		qsort(a,low,pivotLoc-1);
		qsort(a,pivotLoc+1,high);
	}
}



int partition(ElemType a[],int low,int high)
{
	ElemType pivotKey = a[low];
	while (low < high)
	{
		//���ƶ�����ָ�룬�������ƶ�Ԫ��ʱ�Ḳ��a[high]
		while (low < high && !compare(a[high],pivotKey))
		{
			high--;
		}
		a[low] = a[high];
		while (low < high && compare(a[low],pivotKey))
		{
			low++;
		}
		a[high] = a[low];
	}
	a[low] = pivotKey;
	return low;
}



//�鲢����
void mergeSort(ElemType a[],int n)
{
	msort(a,a,0,n-1);
}



//��a[s..t]�鲢����Ϊb[s..t]
void msort(ElemType a[],ElemType b[],int s,int t)
{
	if (s == t)
	{
		b[s] =  a[s];
	}else
	{
		int m = (s+t)/2;
		msort(a,b,s,m);
		msort(a,b,m+1,t);
		merge(a,b,s,m,t);
	}
}



//�������a[s..m]��a[m+1..n]�鲢Ϊ�����b[s,n]
void merge(ElemType a[],ElemType b[],int s,int m,int n)
{
	int i = s,j=m+1,k=0;
	for (; i <= m && j <= n;)
	{
		if (compare(a[i],a[j]))
		{
			b[k++] = a[i++];
		}else
		{
			b[k++] = a[j++];
		}
	}
	if (i<=m)
	{
		for (;i<=m && k<=n;)
		{
			b[k++] = a[i++];
		}
	}else
	{
		for (;j<=n && k<=n;)
		{
			b[k++] = a[j++];
		}
	}
}



void bubbleSort(ElemType a[],int n,int (* compare)(ElemType,ElemType))
{
	for (int i = 0; i <= n-2; i++)
	{
		for (int j = 0; j <= n-i-2; j++)
		{
			if (compare(a[j+1],a[j]))
			{
				//���Դ�ָ��
				swap(a,j+1,j);
			}
		}
	}
}



void insertSort(ElemType a[],int n,int (* compare)(ElemType,ElemType))
{
	for (int i = 1; i < n; i++)
	{
		if (compare(a[i],a[i-1]))
		{
			//�ڱ�
			ElemType sentry = a[i];
			int j;
			//�˴�Ӧ��sentry��a[j]�Ƚϣ�a[i]��ֵ�Ѿ��仯
			for (j = i-1; compare(sentry,a[j]) && j >= 0; j--)
			{
				a[j+1] = a[j];
			}
			a[j+1] = sentry;
		}
	}
}


void selectSort(ElemType a[],int n,int (* compare)(ElemType,ElemType))
{
	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		int j;
		for (j = i+1; j < n; j++)
		{
			if (compare(a[j],a[min]))
			{
				min = j;
			}
		}
		//printf_s("min:%d  j:%d\n",min,j);
		if (min != i)
		{
			//swap(a[j+1],a[j]); ���Դ�ָ��
			swap(a,i,min);
		}
	}
}