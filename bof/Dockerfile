#docker build -t "bof" .
#docker run --name "bof" -d -p 8001:8001 [IMAGE]

FROM ubuntu:16.04
#installation
RUN dpkg --add-architecture i386
RUN apt-get update && apt-get upgrade -y 
RUN apt-get install -y socat build-essential libc6:i386 libncurses5:i386 libstdc++6:i386

#user
RUN adduser --disabled-password --gecos '' bof
RUN chown -R root:bof /home/bof/
RUN chmod 750 /home/bof
RUN chmod 740 /usr/bin/top
RUN chmod 740 /bin/ps
RUN chmod 740 /usr/bin/pgrep
RUN export TERM=xterm

WORKDIR /home/bof/

COPY bof /home/bof
COPY flag /home/bof

RUN chown root:bof /home/bof/flag
RUN chmod 440 /home/bof/flag

RUN strip -s bof

EXPOSE 8001
CMD su bof -c "socat -T10 TCP-LISTEN:8001,reuseaddr,fork EXEC:/home/bof/bof"
