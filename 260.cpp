/*假如这两个数为a和b，那么将所有的数异或得到的数必定为a^b。由于a和b不相等，那么a^b != 0，也就是说在a^b中必定至少有一位为1，对应位上a与b不一样，根据这一位，我们可以将a和b分开，并将数分成两组。注意，两个相同的数肯定会被分到同一个组。    我们在结果数字中找到第一个为1的位的位置，记为第N位。现在我们以第N位是不是1为标准把原数组中的数字分成两个子数组，第一个子数组中每个数字的第N位都为1，而第二个子数组的每个数字的第N位都为0。

现在我们已经把原数组分成了两个子数组，每个子数组都包含一个只出现一次的数字，而其他数字都出现了两次。因此到此为止，所有的问题我们都已经解决。*/
// a & -a :返回第一个非零位置
vector<int> singleNumber(vector<int>& nums) {
    int a = 0, b = 0;
    for (int n : nums)                 a ^= n;
    for (int n : nums) if (n & a & -a) b ^= n;
    return {a ^ b, b};
}
