from random import randint

print '{} {}'.format(100000, 10000)
s = ''
for i in range(0, 100000):
    s += str(randint(0, 9))
print s
for i in range(1,100001):
    print "{}".format(i)
