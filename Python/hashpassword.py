import hashlib
hashvalue = input(“* Enter a string to hash:”)

hash_obj_1=hashlib.md5()
hash_obj_1.update(hashvalue.encode())
print(“md5: “,hash_obj_1.hexdigest())

hash_obj_2=hashlib.sha1()
hash_obj_2.update(hashvalue.encode())
print(“sha1: “,hash_obj_2.hexdigest())

hash_obj_3=hashlib.sha256()
hash_obj_3.update(hashvalue.encode())
print(“sha256: “,hash_obj_3.hexdigest())

hash_obj_4=hashlib.sha224()
hash_obj_4.update(hashvalue.encode())
print(“sha224: “,hash_obj_4.hexdigest())

hash_obj_5=hashlib.sha512()
hash_obj_5.update(hashvalue.encode())
print(“sha512: “,hash_obj_5.hexdigest())
