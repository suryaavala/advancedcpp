template <typename T> struct numeric_limits {
  static T min();
};

template <> struct numeric_limits<int> {
  static int min() { return -__INT_MAX__ - 1; }
};

template <> struct numeric_limits<unsigned int> {
  static int min() { return 0; }
};

template <> struct numeric_limits<float> {
  static float min() { return __FLT_MIN__; }
};
