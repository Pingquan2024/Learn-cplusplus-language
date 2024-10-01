# 饮料瓶回收系统
t = 0
v = 0
sum = 0


def reward(t, v):
    if t == 0:
        if v < 500:
            # 0.08
            return 0.08
        else:
            # 0.1
            return 0.1
    else:
        if v < 10:
            # 0.06
            return 0.06
        else:
            # 0.09
            return 0.09


for i in range(10):
    t = input("请输入饮料瓶的类型（0表示塑料瓶，1表示易拉罐）：")
    v = int(input("请输入单个饮料瓶的重量："))
    sum = sum + reward(t, v)
print("总的金额为：%.2f元" % sum)
