def accum(s):
    list_word = list(s)
    gen_list = []
    
    for i in range(len(list_word)):
        gen_list.append(list_word[i] * (i + 1))
    
    output_string = ""
    
    for word in gen_list:
        if len(word) != len(s):
            output_string += "{}-".format(word)
        else:
            output_string += "{}".format(word)
            
    return output_string.title()
