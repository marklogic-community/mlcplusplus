# Readme for the groupandaggregate UDF

This UDF takes a set of tuples with two values. Using the first as a group-by clause, and the second as a numeric.

For each group discovered from the value of group-by, the ages are added together and a mean is calculated.

The UDF returns something like the below:-

mean|count|groupBy|total
---|---|---|---
25|25000|Fish|625000

Other aggregation functions can also be supported which return different results. For this first implementation,
only a mean average and the columns above are supported.

## Installation

Run make in the folder with the cpp and Makefile files. This generates a zip file for your UDF.

Then run the following in QConsole, substituting the folder for the location on MarkLogic Server 
where the zip file is located:-

```xquery
xquery version "1.0-ml";
import module namespace plugin = "http://marklogic.com/extension/plugin" at "MarkLogic/plugin/plugin.xqy";
plugin:install-from-zip("native", xdmp:document-get("/mnt/hgfs/adamfowler/Documents/marklogic/git/mlcplusplus/release/samples/cppcustomudf/groupandaggregate.zip")/node())
```

## Running the UDF

Against from QConsole, run something like the below:-

```xquery
xquery version "1.0-ml";
cts:aggregate(
  "native/groupandaggregate",
  "groupandaggregate",
  (
    cts:element-reference(xs:QName("animal"),("collation=http://marklogic.com/collation/codepoint"))
    ,
    cts:element-reference(xs:QName("age"),())
  ),  ("aggregate=mean"), ("fragment-frequency"), 
  cts:collection-query("zoo")
)
```

Note: You can use the following aggregate configuration:-
- "aggregate=mean" (default) - calculates a mean of the value for each group
- "aggregate=sum" - calculates the sum (total) only for each group

Note the above example assumes JSON data like the following, in the 'zoo' collection:-

```json
{
"name": "Fred", 
"summary": "Big scary cat", 
"age": 30, 
"animal": "Tiger", 
"family": "Flintstones"
}
```

The UDF requires a string range index in the codepoint collation on the specified groupBy field (first element reference),
and an integer range index on the second field (value field).
