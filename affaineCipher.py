import math

def go(a,b):
    if b==0:
        return 1
    ans=go(a,int(b/2))%26
    ans=(ans*ans)%26
    if b&1==1:
        ans=(ans*a)%26
    return ans
words={"naimur","rahman"}
def ok(s):
    for i in words:
        if i==s:
            return True
    
    return False
def check(msg,k1,k2):
    str=""
    for i in msg:
        
        val=(((ord(i)-97)*k1)+k2)%26
        val2=(((ord(i)-k2-97+26)%26)*go(k1,11))%26
       # print(chr(val2+97))
        str+=chr(val2+97)
    tmp=""
    for i in range(0,len(str),1):
        tmp+=str[i]
        if ok(tmp):
            return str
        
    return ""
        
    
    
    
def encrypt(msg):
    for i in range(1,26,1):
        if math.gcd(i,26)==1:
            for j in range(0,26,1):
                new_msg=check(msg,i,j)
                if new_msg!="":
                    return new_msg
                
    return ""
                  
                  
#print(go(3,11))
print(encrypt("sfdpne"))
