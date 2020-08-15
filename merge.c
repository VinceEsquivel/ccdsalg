void mergeSort(int numbers[], int temp[], int array_size)
{
      int ctr = 0;
      m_sort(numbers, temp, 0, array_size - 1, &ctr);
}

void m_sort(int numbers[], int temp[], int left, int right, int *ctr)
{
      int mid;
      (*ctr)++;
      if (right > left)
      {
            ctr++;
            mid = (right + left) / 2;
            m_sort(numbers, temp, left, mid, ctr);
            m_sort(numbers, temp, mid + 1, right, ctr);
            merge(numbers, temp, left, mid + 1, right, ctr);
      }
}

void merge(int numbers[], int temp[], int left, int mid, int right, int *ctr)
{

      int i, left_end, num_elements, tmp_pos;
      left_end = mid - 1;
      tmp_pos = left;
      num_elements = right - left + 1;
      (*ctr)++;
      while ((left <= left_end) && (mid <= right))
      {
            (*ctr)++;

            if (numbers[left] <= numbers[mid])
            {
                  temp[tmp_pos] = numbers[left];
                  tmp_pos = tmp_pos + 1;
                  left = left + 1;
                  (*ctr)++;
            }
            else
            {
                  temp[tmp_pos] = numbers[mid];
                  tmp_pos = tmp_pos + 1;
                  mid = mid + 1;
                  (*ctr)++;
            }
      }

      (*ctr)++;

      while (left <= left_end)
      {
            temp[tmp_pos] = numbers[left];
            left = left + 1;
            tmp_pos = tmp_pos + 1;
            (*ctr)++;
      }

      (*ctr)++;

      while (mid <= right)
      {
            temp[tmp_pos] = numbers[mid];
            mid = mid + 1;
            tmp_pos = tmp_pos + 1;
            (*ctr)++;
      }

      (*ctr)++;

      for (i = 0; i <= num_elements; i++)
      {
            numbers[right] = temp[right];
            right = right - 1;
            (*ctr)++;
      }
}
