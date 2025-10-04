class Interval:
    def __init__(self, interval_str: str):
        start_str, end_str = interval_str.split("-")
        self.start = Interval.time_str_to_num(start_str)
        self.end = Interval.time_str_to_num(end_str)

    @staticmethod
    def time_str_to_num(time_str: str) -> int:
        hh, mm = int(time_str[:2]), int(time_str[2:])
        return hh*60+mm

    def round(self):
        self.start = self.start//5*5
        self.end = (self.end + 5 - 1)//5*5

    def get_interval_str(self):
        s_hh, s_mm = self.start//60, self.start%60
        e_hh, e_mm = self.end//60, self.end%60
        return f"{s_hh:02}{s_mm:02}-{e_hh:02}{e_mm:02}"

    def __lt__(self, other):
        return self.start < other.start


n = int(input())
intervals = [Interval(input()) for _ in range(n)]

for interval in intervals:
    interval.round()
intervals.sort()

result = []
current = Interval(intervals[0].get_interval_str())
for i in range(1, n):
    if intervals[i].start <= current.end:
        current.end = max(intervals[i].end, current.end)
    else:
        result.append(Interval(current.get_interval_str()))
        current = Interval(intervals[i].get_interval_str())
result.append(Interval(current.get_interval_str()))

for interval in result:
    print(interval.get_interval_str())