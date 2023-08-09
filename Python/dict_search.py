json = {
    "name": "Name",
    "surname": "Surname",
    "options": {
        "option1": {
            "field": "1",
            "field1": "1",
            "field2": {
                "option_key_value": 1,
                "option_key": {
                    "option_surname": 1,
                    "visible": True
                },
                "option_general": 1
            }
        },
        "option2": {
            "field_": "212"
        },
        "option3": "ex"
    },
    "new_field": "field"
}


def go():
    key = input("Write the key you want to search: ")
    search(key, json)


def search(key: str, dict_: dict):
    for e in dict_:
        if type(dict_[e]) == dict and e != key:
            search(key, dict_[e])
        else:
            if e == key:
                print("Element found: {" + f"{e}: {dict_[e]}" + "}")
                return


go()
