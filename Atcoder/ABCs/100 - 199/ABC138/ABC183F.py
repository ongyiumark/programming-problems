l, r = list(map(int, input().split()))
MOD = 10**9 + 7


msb = 70
dp = [[[[0,0] for k in range(2)] for j in range(2)] for i in range(msb+2)]

dp[0][True][True][False] = 1

for i in range(msb+1):
    l_bit = bool((1<<(msb-i))&l)
    r_bit = bool((1<<(msb-i))&r)

    for r_flag in [True, False]:
        for l_flag in [True, False]:
            for start_flag in [True, False]:
                current = dp[i][r_flag][l_flag][start_flag]

                # x = 0 and y = 0
                if (l_flag == False) or (l_bit == 0):
                    dp[i+1][False if 0 < r_bit else r_flag][l_flag][start_flag] += current
                    dp[i+1][False if 0 < r_bit else r_flag][l_flag][start_flag] %= MOD
                
                # x = 1 and y = 0
                if ((r_flag == False) or (r_bit == 1)) and ((l_flag == False) or (l_bit == 0)) and start_flag:
                    dp[i+1][r_flag][l_flag][start_flag] += current
                    dp[i+1][r_flag][l_flag][start_flag] %= MOD
                
                # x = 1 and y = 1
                if (r_flag == False) or (r_bit == 1):
                    dp[i+1][r_flag][False if 1 > l_bit else l_flag][True] += current
                    dp[i+1][r_flag][False if 1 > l_bit else l_flag][True] %= MOD

result = 0
for r_flag in [True, False]:
    for l_flag in [True, False]:
        result += dp[msb+1][r_flag][l_flag][True]

result %= MOD
print(result)