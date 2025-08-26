#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
    * DATA STRUCTURE
    * [ARRAY]   [STRUCT]
    * [LINKED LIST] [STACK] [QUEUE]
 *----------------------------------------------------------------------------*/
    typedef char Element_Type;

    typedef struct Singly_Linked_List    /*[Linked List]*/
    {
        Element_Type data;
        struct Singly_Linked_List *Next;
    } Singly_Linked_List;           

    Singly_Linked_List *InsertToHead(Singly_Linked_List *Head, Element_Type X)
    {
        Singly_Linked_List *Temp = (Singly_Linked_List *)malloc(sizeof(Singly_Linked_List));
        Temp->data = X;
        Temp->Next = Head;
        return Head; 
    }

    Singly_Linked_List *InsertToMiddle(Singly_Linked_List *Prev, Element_Type X)
    {
        Singly_Linked_List *Temp = (Singly_Linked_List *)malloc(sizeof(Singly_Linked_List));
        Temp->data = X;
        Temp->Next = Prev->Next;
        Prev->Next = Temp;
        return Temp;
    }
    
    Singly_Linked_List *InsertToLast(Singly_Linked_List *Head, Element_Type X)
    {
        Singly_Linked_List *Temp;
        Singly_Linked_List *NewNode = (Singly_Linked_List *)malloc(sizeof(Singly_Linked_List));
        NewNode->data = X;
        Temp = Head;
        while (Temp->Next != NULL)
            Temp = Temp->Next;
        Temp->Next = NewNode;
        return Head;
    }

    Singly_Linked_List *DeleteHead(Singly_Linked_List *Head)
    {
        Singly_Linked_List *Temp;
        Temp = Head->Next;
        free(Head);
        return Temp;
    }

    Element_Type Delete(Singly_Linked_List *Prev)
    {
        Element_Type X;        
        Singly_Linked_List *Temp;
        Temp = Prev->Next;
        Prev->Next = Temp->Next;
        X = Temp->data;
        free(Temp);
        return X;
    }

    Singly_Linked_List *DeleteLast(Singly_Linked_List *Head)
    {
        Singly_Linked_List *Temp1, *Temp2;
        Temp1 = Head;
        Temp2 = Head;
        while (Temp1->Next != NULL)
        {
            Temp2 = Temp1;
            Temp1 = Temp1->Next;
        }
        Temp2->Next = NULL;
        free(Temp1);
        return Head;
    }

    int IsEmpty(Singly_Linked_List *Head)
    {
        return !Head;
    }

    Singly_Linked_List *MakeNull(Singly_Linked_List *Head)
    {
        while (!L_IsEmpty(Head))
            Head = L_DeleteHead(Head);
        return Head;
    }

    void Print(Singly_Linked_List *Head)
    {
        Singly_Linked_List *Temp;
        Temp = Head;
        while (Temp)
        {
            printf("%s ", Temp->data);
            Temp = Temp->Next;
        }
        printf("\n");
    }

    typedef struct StackNode    /*[Stack]*/
    {
        Element_Type item;
        struct StackNode *Next;
    } StackNode;
    typedef struct Stack
    {
        struct Stack *top;
    } Stack;
    
    Stack *StackInit()
    {
        Stack *s = (Stack *)malloc(sizeof(Stack));
        if (s == NULL)
            return NULL;
        s->top = NULL;
        return s;
    }

    int StackEmpty(Stack *s)
    {
        return (s->top == NULL);
    }

    int StackFull()
    {
        printf ("\nKhong con cho chua!");
        getch();
        return 1;
    }

    int StackPush(Stack *s, Element_Type *item)
    {
        StackNode *node = (StackNode *)malloc(sizeof(StackNode));
        if (node == NULL)
        {
            StackFull();
            return 1;
        }
        node->item = item;
        node->Next = s->top;
        s->top = node;
        return 0;
    }

    Element_Type StackPop(Stack *s)
    {
        Element_Type item;
        StackNode *node;
        if (StackEmpty(s))
        {
            printf ("\nStack rong!");
            return NULL;
        }
        node = s->top;
        item = node->item;
        s->top = node->Next;
        free(node);
        return item; 
    }

    void disp(Stack *s)
    {
        StackNode *node;
        Element_Type item;
        printf ("\n DANH SACH CAC PHAN TU NGAN XEP: \n");
        if(StackEmpty(s))
        {
            printf ("\nStack rong!");
            getch(); 
        }
        else
        {
            node = s->top;
            do
            {
                item = node->item;
                printf ("%s ", item);
                node = node->Next;
            } while (!(node == NULL));            
        }
    }

    void StackDestroy(Stack *s)
    {
        while (!StackEmpty(s))
            StackPop(s);
        free(s);
    }

    typedef struct Qnode    /*[Queue]*/
    {
        Element_Type element;
        struct Qnode *Next;
    } Qnode;
    typedef struct Queue
    {
        Qnode *front;
        Qnode *back;
    } Queue;
    
    Queue *Create()
    {
        Queue *q = (Queue *)malloc(sizeof(Queue));
        if (q == NULL)
            return NULL;
        q->back = NULL;
        q->front = NULL;
        return q;
    }

    int QIsEmpty(Queue *q)
    {
        return ((q->back == NULL) && (q->front == NULL));
    }

    int QSize(Queue *q)
    {
        Qnode *ptr = q->front;
        int count = 0;
        while (ptr != NULL)
        {
            ptr = ptr->Next;
            count++;
        }
        return count;
    }

    void EnQueue(Queue *q, Qnode *newNode)
    {
        if (!QIsEmpty(q))
        {
            q->back->Next = newNode;
            q->back = newNode;
        }
        else
        {
            q->back = newNode;
            q->front = newNode;
        }        
    }

    Qnode *DeQueue(Queue *q)
    {
        Qnode *ptr = q->front;
        if (ptr != NULL)
        {
            q->front = q->front->Next;
            if (q->front == NULL)       
                q->back = NULL;
            ptr->Next = NULL;            
        }
        return ptr;
    }

/*------------------------------------------------------------------------------
    * TREE
    * [BINARY TREE]
 *----------------------------------------------------------------------------*/
    typedef int DataType;
    typedef struct Tnode
    {
        DataType Item;
        struct Tnode *left;
        struct Tnode *right;
    } treeNode;
 
    treeNode *makeTreeNode(int x)
    {
        treeNode *newNode = NULL;
        newNode = (treeNode*)malloc(sizeof(treeNode));
        if(newNode==NULL)
        {
            printf("Het bo nho \n");
            exit(1);
        }
        else
        {
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->Item = x;
        }
        return newNode;
    }

    int countNodes(treeNode *tree)
    {
        if(tree==NULL) 
            return 0;
        else
        {
            int ld = countNodes(tree->left);
            int rd = countNodes(tree->right);
            return 1+ld+rd;
        }
    }

    int depth(treeNode *tree)
    {
        if(tree==NULL) 
            return 0;
        int ld = depth(tree->left);
        int rd = depth(tree->right);
        return 1+(ld>rd ? ld : rd);
    }

    void freeTree(treeNode *tree)
    {
        if(tree=NULL) 
            return;
        freeTree(tree->left);
        freeTree(tree->right);
        free(tree);
        return;
    }

    void printPreorder(treeNode *tree)
    {
        if(tree!=NULL)
        {
            printf("%5d",tree->Item);
            printPreorder(tree->left);
            printPreorder(tree->right);
        }
    }

    void printInorder(treeNode *tree)
    {
        if(tree!=NULL)
        {
            printInorder(tree->left);
            printf("%5d",tree->Item);
            printInorder(tree->right);
        }
    }

    void printPostrder(treeNode *tree)
    {
        if(tree!=NULL)
        {
            printPostorder(tree->left);
            printPostorder(tree->right);
            printf("%5d",tree->Item);
        }
    }
/*------------------------------------------------------------------------------
    * SORT 
    * [INSERTION SORT]  [SELECTION SORT]  [BUBBLE SORT]
    * [MERGE SORT]  [QUICK SORT]
    * [HEAP SORT]
 *----------------------------------------------------------------------------*/
    void Swap(float *a, float *b) /*[Swap]*/
    {
        float temp = *a;
        *a = *b;
        *b = temp;        
    }

    void Insertion_Sort(float A[], int n)   /*[Insertion Sort]*/
    {
        for (int i = 1; i < n; i++)
        {
            int j = i;
            float key = A[i];
            while(j > 0 && A[j - 1] > A[j])
            {
                A[j] = A[j - 1];
                j--;
            }
            A[j] = key;
        }
    }

    void Selection_Sort(float A[], int n)   /*[Selection Sort]*/
    {
        for (int i = 0; i < n - 1; i++)
        {
            int key = i;
            for (int j = i + 1; j < n; j++)
                if (A[key] > A[j])
                    key = j;
            Swap(&A[i], &A[key]);
        }
    }

    void Bubble_Sort(float A[], int n)  /*[Bubble Sort]*/
    {
        for (int i = n - 1; i > 0; i --)
            for (int j = 0; j <= i; j++)
                if (A[j] > A[j + 1])
                    Swap(&A[j], &A[j + 1]);        
    }

    void Merge(float A[], int first, int mid, int last) /*[Merge Sort]*/
    {
        float L[mid - first + 2], R[last - mid + 1];
        for (int i = first; i <= mid; i++)
            L[i - first] = A[i];
        L[mid - first + 1] = 1e9;
        for (int i = mid + 1; i <= last; i++)
            R[i - mid - 1] = A[i];
        R[last - mid] = 1e9;

        int i = 0;
        int j = 0;

        for(int key = first; key <= last; key++)
        {
            if (L[i] <= R[j])
            {
                A[key] = L[i];
                i++;
            }
            else
            {
                A[key] = R[j];
                j++;
            }
        }
    }
    void Merge_Sort(float A[], int first, int last)
    {
        if (first < last)
        {
            int mid = (first + last) / 2;
            Merge_Sort(A, first, mid);
            Merge_Sort(A, mid + 1, last);
            Merge(A, first, mid, last);
        }
    }

    int Partition(float A[], int left, int right)  /*[Quick Sort]*/
    {
        int i = left, j = right;
        float pivot = A[left];
        while (i < j)
        {
            while (i <= right && A[i] <= pivot)
                i++;
            while (j >= left && A[j] > pivot)
                j--;
            if (i < j)
                Swap(&A[i], &A[j]);
        }
        Swap(&A[left], &A[j]);
        return j;
    }
    void Quick_Sort(float A[], int left, int right)
    {
        if(left < right)
        {
            int p = Partition(A, left, right);
            Quick_Sort(A, left, p - 1);
            Quick_Sort(A, p + 1, right);
        }
    }

    void Max_Heapify(float A[], int i, int n)    /*[Heap Sort]*/
    {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int largest = i;
        if (left_child < n && A[left_child] > A[i])
            largest = left_child;
        if (right_child < n && A[right_child] > A[largest])
            largest = right_child;
        if (largest != i)
        {
            Swap(&A[i], &A[largest]);
            Max_Heapify(A, largest, n);
        }
    }
    void Build_Max_Heap(float A[], int n)
    {
        for (int i = n/2 - 1; i >= 0; i--)
            Max_Heapify(A, i, n);
    }
    void Heap_Sort(float A[], int n)
    {
        Build_Max_Heap(A, n);
        for (int i = n - 1; i > 0; i--)
        {
            Swap(&A[0], &A[i]);
            Max_Heapify(A, 0, i);
        }
    }

/*------------------------------------------------------------------------------
    * SEARCHING
    * [Linear Search] [Binary Search]
    * [Binary Seach Tree]   [Adelson - Velskii - Landis]
    * [Mappping & Hashing]
 *----------------------------------------------------------------------------*/
    int Linear_Search(float A[], int n, float target)   /*[Linear Search]*/
    {
        for (int i = 0; i < n; i++)
            if (A[i] == target)
                return i;
        return -1;
    }

    int Binary_Search(float A[], int n, float target)   /*[Binary Search]*/
    {
        int lower = 0, upper = n - 1, mid;
        while (lower <= upper)
        {
            mid = (upper + lower) / 2;
            if (A[mid] > target)
                upper = mid - 1;
            else if (A[mid] < target)
                lower = mid + 1;
            else 
                return mid;
        }
        return -1;
    }

    treeNode *Inser(treeNode *nodePtr, DataType item)   /*[Binary Seach Tree]*/
    {
        if (nodePtr == NULL)    
            nodePtr = makeTreeNode(item);
        else if (item < nodePtr->Item)
            nodePtr->left = Inser(nodePtr->left, item);
        else if (item > nodePtr->Item)
            nodePtr->right = Inser(nodePtr->right, item);
        return nodePtr;        
    }

    treeNode *Seach(treeNode *nodePtr, DataType target)
    {
        if (nodePtr != NULL)
        {
            if (target < nodePtr->Item)
                nodePtr = Seach(nodePtr->left, target);
            else if (target > nodePtr->Item)
                nodePtr = Seach(nodePtr->right, target);            
        }
        return nodePtr;
    }

    treeNode *FindMin(treeNode *nodePtr)
    {
        while (nodePtr->left != NULL)        
            nodePtr = nodePtr->left;        
        return nodePtr;
    }

    treeNode *FindMax(treeNode *nodePtr)
    {
        while (nodePtr->right != NULL)        
            nodePtr = nodePtr->right;        
        return nodePtr;
    }

    treeNode *treeDelete(treeNode *T, DataType X)
    {
        treeNode *Tmp;
        if (T == NULL)
            printf ("Not Found!");
        else if (X < T->Item)
            T->left = treeDelete(T->left, X);
        else if (X > T->Item)
            T->right = treeDelete(T->right, X);
        else if (T->left && T->right)
        {
            Tmp = FindMin(T->right);
            T->Item = Tmp->Item;
            T->right = treeDelete(T->right, Tmp->Item);
        }
        else 
        {
            Tmp = T;
            if (T->left == NULL)
                T = T->right;
            else if (T->right == NULL)
                T = T->left;
            free(Tmp);
        }
        return T;
    }