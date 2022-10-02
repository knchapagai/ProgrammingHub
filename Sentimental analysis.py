#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
import nltk
from nltk.corpus import stopwords
from nltk.classify import SklearnClassifier
from sklearn.model_selection import train_test_split
from wordcloud import WordCloud,STOPWORDS
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.metrics import confusion_matrix, classification_report


# In[2]:


df=pd.read_csv("C:\\Users\\ankit\\Documents\\Project Files\\Sentiment.csv")
df.head()


# In[3]:


df=df.drop(df[['id','candidate','candidate_confidence','name','relevant_yn','relevant_yn_confidence','sentiment_confidence','subject_matter','subject_matter_confidence','candidate_gold','relevant_yn_gold','retweet_count','sentiment_gold','subject_matter_gold','tweet_coord','tweet_created','tweet_id','tweet_location','user_timezone']],axis=1)


# In[4]:


df.head()


# In[5]:


df.isnull().sum()


# In[6]:


filt=df["sentiment"]=="Neutral"
df.drop(index=df[filt].index,inplace=True)


# In[7]:


df


# In[8]:


list=["sentiment"]
new_list=["sentiment"]
label=LabelEncoder()
list1=[]
for i in list:
    list1.append(label.fit_transform(df[i]))


# In[9]:


new_list=["sentiment"]
for i in range(len(list)):
    df[new_list[i]]=list1[i]


# In[10]:


df["sentiment"]


# In[11]:


def wordcloud_draw(data, color = 'black'):
    words = ' '.join(data)
    cleaned_word = " ".join([word for word in words.split()
                            if 'http' not in word
                                and not word.startswith('@')
                                and not word.startswith('#')
                                and word != 'RT'
                            ])
    wordcloud = WordCloud(stopwords=STOPWORDS,
                      background_color=color,
                      width=2500,
                      height=2000
                     ).generate(cleaned_word)
    plt.figure(1,figsize=(13, 13))
    plt.imshow(wordcloud)
    plt.axis('off')
    plt.show()
    
print("Useful words")
wordcloud_draw(df['text'],'black')
#print("Negative words")
#wordcloud_draw(train_neg)


# In[12]:


import nltk  ## Preprocessing our text
from nltk.corpus import stopwords ## removing all the stop words
from nltk.stem.porter import PorterStemmer 
import re
lent=len(df) 
corpus111=[]
for i in range(0,lent):
    text = re.sub('[^a-zA-Z]', ' ', df.iloc[i,1])
    text = text.lower()
    text = text.split()
    ps = PorterStemmer()
    all_stopwords = stopwords.words('english')
    #all_stopwords.remove('rt')      
    text = [ps.stem(word) for word in text if not word in   set(all_stopwords)]
    stopw={'rt','http'}
    text= [ps.stem(word) for word in text if not word in   set(stopw)]
    text = ' '.join(text)
    corpus111.append(text)     


# In[13]:


df['Cleared Data']=corpus111


# In[14]:


df.tail()


# In[15]:


df['sentiment'].value_counts()


# In[16]:


X=df['Cleared Data']
y=df['sentiment']


# In[17]:


X


# In[18]:


X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.2,random_state=40)


# In[19]:


from sklearn.feature_extraction.text import CountVectorizer
cv=CountVectorizer()    # it used to converting string data inta float data for further preduction
X_train=cv.fit_transform(X_train)
X_test=cv.transform(X_test)


# In[20]:


print(cv.vocabulary_)


# In[21]:


from sklearn.naive_bayes import MultinomialNB
model5 = MultinomialNB()
Navies=model5.fit(X_train,y_train)
predict_nb=Navies.predict(X_test)
print(classification_report(y_test,predict_nb))
print(confusion_matrix(y_test,predict_nb))


# In[22]:


rfc=RandomForestClassifier(n_estimators=200)
rfc.fit(X_train,y_train)
predict_rfc=rfc.predict(X_test)
print(classification_report(y_test,predict_rfc))
print(confusion_matrix(y_test,predict_rfc))


# In[23]:


from sklearn.neural_network import MLPClassifier
mlpc=MLPClassifier(hidden_layer_sizes=(8,8,8),max_iter=400)
mlpc.fit(X_train,y_train)
predic_mlpc = mlpc.predict(X_test)
print(classification_report(y_test,predic_mlpc))
print(confusion_matrix(y_test,predic_mlpc))


# In[24]:


rfc.score(X_train,y_train)


# In[25]:


rfc.score(X_test,y_test)


# In[26]:


mlpc.score(X_train,y_train)


# In[27]:


model5.score(X_train,y_train)


# In[30]:


model=RandomForestClassifier(n_estimators=200,criterion='entropy',
                             max_features='sqrt',min_samples_leaf=10,random_state=100).fit(X_train,y_train)
predictions=model.predict(X_test)
print(confusion_matrix(y_test,predictions))
#print(accuracy_score(y_test,predictions))
print(classification_report(y_test,predictions))

