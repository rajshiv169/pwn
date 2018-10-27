#docker build -t "ieat" .
#docker run --name "ieat" -d -p 8002:8002 [IMAGE]

FROM ubuntu:16.04
#installation
RUN dpkg --add-architecture i386
RUN apt-get update && apt-get upgrade -y 
RUN apt-get install -y socat build-essential libc6:i386 libncurses5:i386 libstdc++6:i386

#user
RUN adduser --disabled-password --gecos '' ieat
RUN chown -R root:ieat /home/ieat/
RUN chmod 750 /home/ieat
RUN chmod 740 /usr/bin/top
RUN chmod 740 /bin/ps
RUN chmod 740 /usr/bin/pgrep
RUN export TERM=xterm

WORKDIR /home/ieat/

COPY ieat /home/ieat
COPY flag /home/ieat
COPY dessert /home/ieat

RUN chown root:ieat /home/ieat/flag
RUN chmod 440 /home/ieat/flag

RUN strip -s ieat

EXPOSE 8002
CMD su ieat -c "socat -T10 TCP-LISTEN:8002,reuseaddr,fork EXEC:/home/ieat/ieat"
