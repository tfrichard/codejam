int pure_rank(int n) {
  if (n == 2) return 1;

  int res = 0;
  res = pure_rank_impl(n, n - 1);
  return res;
}

// 1 2...n -> [k]
// 1 2 3 4 -> [3]
// put balls into pins in order
int df(int begin, int end, int space) {
  if (begin > end || end - begin < space) return 0;
  if (space == 0) return 1;

  int res = 0;
  for (int i = begin; i < end; i++) {
    res += df(i + 1, end, space - 1);
  }

  return res;
}

//recursive driver, iterate all sizes of "pure" collections
int pure_rank_impl(int n, int size) {
  int res = 1;
  for (int k = 2; k <= size; k++) {
    res += pure_rank_helper(n, k);
  }

  return res;
}


int pure_rank_helper(int n, int k) {
  if (k == 1) return 1;

  int res = 0;
  int begin = max(1, 2 * k - n);
  int end = k - 1;
  for (int i = begin; i <= end; i++) {
	// check all "free positions" using df utility function
    res += pure_rank_helper(k, i) * df(k + 1, n, k - i - 1);
  }

  return res;
}
