
// node *Merge(node *&first, node *&second)
// {
//     if (first == NULL)
//     {
//         return second;
//     }
//     if (second == NULL)
//     {
//         return first;
//     }

//     node *result = new node(-1);
//     node *temp = result;

//     while (first != NULL && second != NULL)
//     {
//         if (first->data < second->data)
//         {
//             temp->next = first;
//             temp = first;
//             first = first->next;
//         }
//         else
//         {
//             temp->next = second;
//             temp = second;
//             second = second->next;
//         }
//     }

//     while (first != NULL)
//     {
//         temp->next = first;
//         temp = first;
//         first = first->next;
//     }
//     while (second != NULL)
//     {
//         temp->next = second;
//         temp = second;
//         second = second->next;
//     }

//     result = result->next;

//     return result;
// }
