import os

filelist = []
for root, dirs, files in os.walk("./"):
    for file in files:
        if file.endswith(".txt"):
            filelist.append(file)

for path in filelist:
    with open("./" + path, mode = "r", encoding = "utf8") as file:
        text = file.read()
        text = text.upper()
        with open("./" + path.replace("0", ""), mode = "w", encoding = "utf8") as file2:
            file2.write(text)

    print (path)
        
