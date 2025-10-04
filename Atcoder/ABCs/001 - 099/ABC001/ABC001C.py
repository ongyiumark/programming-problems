directions = ["N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"]
speed_range = [0, 3, 16, 34, 55, 80, 108, 139, 172, 208, 245, 285, 327]

def convert_deg(deg_100):
    step = 36_000//32
    index = (deg_100//step+1)%32
    return directions[index//2]

def convert_dis(dis):
    speed = dis//6 + int(dis%6 >= 3)
    lo = 0
    hi = len(speed_range)-1
    ans = 0
    while lo <= hi:
        mid = hi - (hi-lo)//2
        if speed >= speed_range[mid]:
            ans = mid
            lo = mid+1
        else:
            hi = mid-1
    return ans
    

deg, dis = [int(x) for x in input().split()]
result_deg, result_dis = convert_deg(deg*10), convert_dis(dis)
if result_dis == 0: result_deg = "C"
print(result_deg, result_dis)