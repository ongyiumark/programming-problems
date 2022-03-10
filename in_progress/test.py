import datetime
a = "08:40 AM"

print(datetime.datetime.strptime("12:00 PM", "%I:%M %p") > datetime.datetime.strptime("1:00 AM", "%I:%M %p"))