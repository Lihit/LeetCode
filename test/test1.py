f=open('fireTest.py','r')
for line in f:
    print(line)

f.seek(0)
lines=f.readlines()
print(lines)
f.close()
