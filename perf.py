#!/usr/bin/python
import re

# Define patterns we want to recognize.

c = r'(\S+)\s+'  # a word we want to capture
s = r'\S+\s+'  # a word we want to skip
func = r'\[[a-zA-Z<>:_]+ ([a-zA-Z:])+\([a-zA-Z :&\*]+\)\] in \[(\d*) ms\]'
executed = r'Executed\s'
func = r'\[[a-zA-Z:]+\s([a-zA-Z:_0-9]+)\(.*\)\]\s'



func2 = r'\[.+\s[*]?([a-zA-Z:_0-9]+)\(.*\).*\]\s'


anything = r'.*'
duration = r'in\s\[(\d*)\sms\]'
mesg = r'(\S.*\S)\s+--Sev\s+'  # mesg to capture; terminated by string '--Sev'
w2 = r'(\S+\s+\S+)\s+'  # two words separated by some white space
w2semi = r'(\S+\s+\S+)\s*;\s+'  # two words terminated by a semicolon
tail = r'(.*\S)\s*;'

# Join together the above patterns to make one giant pattern that parses
# the input.
s_pat = ( executed + func2 + duration)

# Pre-compile the pattern for speed.
pat = re.compile(s_pat)

# Test string and the expected output result.
s_input = "Executed [std::unique_ptr<Response> mlclient::Connection::getDocument(const std::string &)] in [3 ms]"
#s_input = "Executed [mlclient::TextDocumentContent *mlclient::SearchDescription::getPayload()] in [0 ms]"
s_correct = "mlclient::Connection::getDocument,3"

# re.match() returns a "match group"
m = re.match(pat, s_input)
# m.groups() returns sequence of captured strings; join with '|'
s_output = ",".join(m.groups())

print s_output

# sanity check
if s_correct == s_output:
    print "Test Succeeded"
else:
    print "Test Failed"
    #exit

print "Generating performance.csv from performance.log..."

# excellent.



# NOW PROCESS FILE
inputfile = open('performance.log')
outputfile = open('performance.csv', 'w')

for line in inputfile:
  m = re.match(pat,line)
  #print line + "   =>   "
  #print m.groups()
  st = ",".join(m.groups())
  outputfile.writelines(st + "\n")

inputfile.close()
outputfile.close()

print "Done."
