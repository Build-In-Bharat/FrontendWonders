FROM node

WORKDIR /myapp

COPY . .

RUN npm install mongoose body-parser nodemon express

EXPOSE 4044

CMD [ "node","app.js"]
