
import speech_recognition as sr
import pyttsx3, webbrowser

r = sr.Recognizer() 
# code for speech recog and txt to speech
with sr.Microphone() as source:
    print('Speak anything : ')
    audio = r.listen(source)

    try:
        txt = r.recognize_google(audio)
        print('You said : {}'.format(txt))
        
    except:
        txt = print('Sorry could not recognize your voice')

#code for text to speech
engine = pyttsx3.init()
engine.setProperty('rate',120)
engine.say('You said '+ txt)
engine.runAndWait()
