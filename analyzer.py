with open("keylog1.txt" , "r") as file: #here is a normal reading file operation 
    content = file.readlines() # this is where what is read being stored



key_count = {} #dictionary

lines =0
timestampstart = content[0].strip()

for i in range(0,len(content) , 2): #this moves 2 steps ex 0 , 2 ,4..
    result = content[i] + content[i+1]
    lines+=1
    key = content[i+1].strip() #this part is used to remove new lines at end f each line
    if key in key_count:
        key_count[key]+=1
    else:
        key_count[key]=1
    
    most_freq = max(key_count , key=key_count.get)

timestampend = content[-2].strip()



print("=== Keylogger Analysis ===")
print(f"Session Start : {timestampstart}")
print(f"Session End   : {timestampend}")
print(f"Total Keys    : {lines}")
print(f"Most Frequent : {most_freq}")
print(f"Key Counts    : {key_count}")
