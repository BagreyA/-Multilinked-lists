#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//указатели на предыдущий и следующий элементы списка
typedef struct Node
{
    struct Node *start;
    int value;
    struct Node *next;
} Node;
//указатель на начало, конец первой половины и просто конец 
typedef struct Bok
{
    struct Node *head;
    struct Node *tail;
    struct Node *tail_a1;
} Bok;
//создаем первый элемент списка который принимает на вход значения структуры Воk
Node *createList(int data, Bok *parts)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = NULL;
    tmp->start = NULL;
    parts->tail_a1 = tmp;
    return tmp;
}

Bok *creat()
{
    Bok *tmp = (Bok *)malloc(sizeof(Bok));
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->tail_a1 = NULL;
    return tmp;
}
//добовляем элементы в список
Node *element_start(int data, Node *head, Bok *parts, int size)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = head;
    tmp->start = NULL;
    Node *p = head;
    while (p->next != NULL)
        p = p->next;

    if (size % 2 == 0)
    {
        p->start = tmp;
    }
    parts->head = tmp;
    return (tmp);
}
//добовляем элементы в список
Node *element_start_2(int data, Node *head, Bok *parts)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = parts->tail_a1;
    tmp->start = NULL;
    parts->head = tmp;
    return (tmp);
}
//добовляем элементы в список
void element_end(int data, Node *head, Bok *parts)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = NULL;
    tmp->start = NULL;
    Node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->start = parts->head;
    parts->tail = p->next;
}
//устанавливаем связи ежду списками
void connect(Node *head, Bok *parts)
{
    Node *p = head;
    while (p->next != parts->tail_a1)
        p = p->next;
    parts->tail->next = p;
}
//вывод списка на экран
int print(Node *list, Bok *parts)
{
    while (list)
    {
        printf("%d ", list->value);
        if (list == parts->tail){
            return 0;
        }
        list = list->next;
    }
}
//меню с доступными командами
void menu()
{
    printf("\nСделайте правильный выбор\n");
    printf("Выход - 1\n");
    printf("Направо - 6\n");
    printf("Вниз - 2\n");
    printf("Наверх - 8 (Только если вы на 2 элементе!)\n");
    printf("Хотите начать сначала? - 3");
    printf("\nСделайте другой выбор: ");
}
//прописываем шаги для перемешения
Node *up(Node *list, Bok *patrs)//8
{
    if (list->next == patrs->tail_a1){
        list = (list->next);
        printf("Значение: %d\n", list->value);
    }else{
        printf("Нет хода \n");
    }
    return list;
}
Node *down(Node *list, Bok *patrs)//2
{
    if (list->start != NULL){
        list = (list->start);
        printf("Значение: %d\n", list->value);
    }else{
        printf("Нет хода \n");
    }
    return list;
}
Node *rigth(Node *list, Bok *patrs)//6
{
    if (list->next != NULL){
        list = (list->next);
        printf("Значение: %d\n", list->value);
    }else{
        printf("Нет хода \n");
    }
    return list;
}
int main()
{
    int n, size;
    srand(time(NULL));
    Node *list = NULL;
    Bok *parts;
    parts = creat();
    int array[100], x, xi = 0;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    printf("\nСделайте правильный выбор\n");
    printf("Выход - 1\n");
    printf("Направо - 6\n");
    printf("Вниз - 2\n");
    printf("Наверх - 8 (Только если вы на 2 элементе!)\n");
    list = createList(1, parts);
    for (int i = 2; i <= n; i++)
    {
        if (i == 2){
            list = element_start_2(i, list, parts);
        }else if (i % 2 == 1){
            element_end(i, list, parts);
        }else{
            list = element_start(i, list, parts, n);
        }
    }
    connect(list, parts);
    int choice = 1;
    printf("\n");
    print(parts->head, parts);
    Node *k = parts->tail_a1;
    printf("\nЗначение: %d\n", k->value);
    while (choice != 0)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            menu();
            break;
        case 2:
            k = down(k, parts);
            break;
        case 3:
            k = (parts->tail_a1);
            printf("\nЗначенеи: %d\n", k->value);
            break;
        case 6:
            k = rigth(k, parts);
            break;
        case 8:
            k = up(k, parts);
            break;
        default:
            menu();
            break;
        }
    }
    return 0;
}
