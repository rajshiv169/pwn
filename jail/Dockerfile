#docker build -t "jail" .
#docker run --name "jail" -d -p 8003:8003 [IMAGE]

FROM ubuntu:16.04
	
RUN apt-get update && apt-get upgrade -y 
RUN apt-get install -y python3 socat build-essential

RUN adduser --disabled-password --gecos '' jail
RUN chown -R root:jail /home/jail/
RUN chmod 750 /home/jail
RUN chmod 740 /usr/bin/top
RUN chmod 740 /bin/ps
RUN chmod 740 /usr/bin/pgrep
RUN export TERM=xterm

WORKDIR /home/jail/

COPY jail.py /home/jail

EXPOSE 8003

CMD su jail -c "socat -T60 TCP-LISTEN:8003,reuseaddr,fork EXEC:/home/jail/jail.py"
