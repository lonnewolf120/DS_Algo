import json

# The JSON data
json_data = '''
{
  "documents": [
    {
      "name": "projects/cse23-f4c65/databases/(default)/documents/cse22/202214027",
      "fields": {
        "name": {
          "stringValue": "Arik"
        },
        "message": {
          "stringValue": "heyy"
        },
        "id": {
          "stringValue": "202214027"
        },
        "fb": {
          "stringValue": "arik"
        },
        "image": {
          "stringValue": "https://cdn.discordapp.com/attachments/1100471832949297286/1100490502517825543/a-new.jpg"
        }
      },
      "createTime": "2023-04-25T18:36:26.155804Z",
      "updateTime": "2023-04-25T18:36:26.155804Z"
    },
    {
      "name": "projects/cse23-f4c65/databases/(default)/documents/cse22/202214052",
      "fields": {
        "message": {
          "stringValue": "heyy"
        },
        "fb": {
          "stringValue": "https://www.facebook.com/raisulislam.rahad.104/"
        },
        "image": {
          "stringValue": "https://cdn.discordapp.com/attachments/1100471832949297286/1100491712561938462/316538731_1377364149460402_5913630458502436833_n.jpg"
        },
        "id": {
          "stringValue": "202214052"
        },
        "name": {
          "stringValue": "Md. Raisul Islam Rahad"
        }
      },
      "createTime": "2023-04-25T18:41:13.112133Z",
      "updateTime": "2023-04-25T18:41:13.112133Z"
    },
    {
      "name": "projects/cse23-f4c65/databases/(default)/documents/cse22/202214112",
      "fields": {
        "name": {
          "stringValue": "Yusuf Reza Hasnat"
        },
        "fb": {
          "stringValue": "https://www.facebook.com/yusufreza.hasnat"
        },
        "message": {
          "stringValue": ""
        },
        "image": {
          "stringValue": "https://cdn.discordapp.com/attachments/1100471832949297286/1100494644988608574/1668618388645.jpg"
        },
        "id": {
          "stringValue": "202214112"
        }
      },
      "createTime": "2023-04-25T18:52:52.764992Z",
      "updateTime": "2023-04-25T18:52:52.764992Z"
    }
  ]
}
'''

# Load the JSON data
data = json.loads(json_data)

# Extract the string values of the fields
for document in data['documents']:
    for field in document['fields']:
        print(field + ': ' + document['fields'][field]['stringValue'])
