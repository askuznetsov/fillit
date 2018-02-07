  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:35:10 by abibyk            #+#    #+#             */
/*   Updated: 2018/01/29 15:35:28 by abibyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct  s_shape
{
  char arr[4][4];
}               t_shape;

// typedef struct  s_point
// {
//   int x;
//   int y;
// }               t_point;


void ft_putchar(char c)
{
  write(1,&c,1);
}

int checker(char s) // не факт что пригодится
{
   if (s == '.')
      return(1);
   if (s == '#')
      return(2);
   if (s == '\n')
      return(3);
   return 0;
}

void show(t_shape obj)
{
  int i;
  int j;

  i = 0;
  while(i < 4)
  {
    j = 0;
    while(j < 4)
    {
      ft_putchar(obj.arr[i][j]);
      j++;
    }
    ft_putchar('\n');
    i++;
  }
}

int getSize(char *fileName) // узнаем кол-во пришедших тетриминов
{
  int     file;
  int     size;
  int     row;
  size_t  ret;
  char    ch;

  size = 0;
  row = 0;
  file = open(fileName, O_RDONLY);
  while ((ret = read(file, &ch, 1)) == 1)
  {
      if (ch == '\n')
      {
          row++;
          if (row % 4 == 0)
          {
              size++;
              ret = read(file, &ch, 1);
              // if (ret < 0)
              //     exit(-1);
              // if (ret == 0)
              //   exit(0);
          }
      }
  }
  close(file);
  return(size);
}

void fillArray(char *fileName, t_shape *mas) // !!!по нормам пока не проходит
{
  int     file;
  int     n;
  size_t  ret;
  char    ch;
  int     i;
  int     j;

  file = open(fileName, O_RDONLY);
  n = 0;
  i = 0;
  j = 0;
  while ((ret = read(file, &ch, 1)) > 0)
  {
      if (ch != '\n')
      {
          mas[n].arr[i][j] = ch;
          j++;
          if (j == 4)
          {
              j = 0;
              i++;
              if (i == 4)
              {
                  i = 0;
                  n++;
              }
          }
      }
  }
  close(file);
}

int checkChar(t_shape obj) // проверка на . и #
{
  int i = 0;
  int j = 0;
  while (i < 4)
  {
      j = 0;
      while (j < 4)
      {
          j++;
          if (obj.arr[i][j] != '#' && obj.arr[i][j] != '.')
              return (0);
       }
      i++;
  }
  return(1);
}

int checkBlock(t_shape obj) // проверка чтобы # было ровно 4
{
  int i;
  int j;
  int n;

  i = 0;
  j = 0;
  n = 0;
  while (i < 4)
  {
      j = 0;
      while (j < 4)
      {
          j++;
          if (obj.arr[i][j] == '#')
              n++;
      }
      i++;
  }
  return(n == 4 ? 1 : 0);
}

t_shape cloneShape(t_shape obj) // не факт что пригодится
{
  t_shape   tmp;
  int       i;
  int       j;

  i = 0;
  while(i < 4)
  {
    j = 0;
    while(j < 4)
    {
      tmp.arr[i][j] = obj.arr[i][j];
      j++;
    }
    i++;
  }
  return tmp;
}

int checkFigure(t_shape obj, int x, int y, int count) // проверяем пришел ли нам тетримино или просто 4 # в рандомных местах
{ 
    obj.arr[x][y] = '?';

    // show(obj);
    // printf("\n");
    // printf("count1 - %i\n", count);

    if (y < 3 && obj.arr[x][y + 1] == '#')
      count = checkFigure(obj, x, y + 1, count); 
    if (x < 3 && obj.arr[x + 1][y] == '#')
      count = checkFigure(obj, x + 1, y, count);
    if (y > 0 && obj.arr[x][y - 1] != '.')
      {
        if(obj.arr[x][y - 1] == '#')
          count = checkFigure(obj, x, y - 1, count);
        else
          count = checkFigure(obj, x, y - 1, count - 1);
      }
  count++;
  // printf("count2 - %i\n", count);
  return count;
}

int findBlock(t_shape obj)
{
  int point[2];
  int i;
  int j;
  //t_shape tmp;

  i = 0;
  while(i < 4)
  {
    j = 0;
    while(j < 4)
    {
      if (obj.arr[i][j] == '#')
        {
          point[0] = i;
          point[1] = j;
          printf("i - %i   j - %i\n", i, j);
          // tmp = cloneShape(obj);
          // show(tmp);
          // printf("\n");
          return(checkFigure(obj, point[0], point[1], 0) == 4);
        }
        j++;
    }
    i++;
  }
  return(0);
}

// int checkShape(t_shape obj) // проверяет всю карту на правильность
// {
//   if(checkChar(obj) == 0 || checkBlock(obj) == 0 || findBlock(obj) == 0)
//       return 0;
//  }

void transChar(t_shape *obj, int index) //индекс соответсвует порядковому номеру тетриминоса -первый превратится в А, второй в В и т.д.
{
  int i;
  int j;
  char c;

  c = 65;
  i = 0;
  while(i < 4)
  {
    j = 0;
    while(j < 4)
    {
      if (obj->arr[i][j] == '#')
        obj->arr[i][j] = c + index;
      j++;
    }
    i++;
  } 
}


int main()
{
  t_shape *mas;
  int size;
  int res;
  int i;

  i = 0;
  size = getSize("1.txt");
  printf("%i\n", size);
  mas = (t_shape *) malloc(sizeof(t_shape) * size);
  fillArray("1.txt", mas);
  
  while(i < size)
  {
    res = findBlock(mas[i]);
    printf("%i\n", res);
    i++;  
  }
  

  // res = checkFigure(mas[3], 1, 0);
  // printf("%i", res);



  // for (int k = 0; k <size ; ++k)
  // {
  //     show(mas[k]);
  //     printf("\n");
  // }

  // for (int i = 0; i < size; ++i)
  // {
  //   transChar(&mas[i], i);
  // }  

  // for (int k = 0; k <size ; ++k)
  // {
  //     show(mas[k]);
  //     printf("\n");
  // }

  // res = checkFigure(mas[2], 0, 1);
  // printf("%i\n", res);

  free(mas);
  return(0);
}
