<?xml version = "1.0" encoding = "UTF-8"?>  
<xsl:stylesheet version = "1.0" xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">     
   <xsl:template match = "/" >  
      
         <table border = "1" style="color:blue;font-size:40px" >
         
          <tr ><td> <xsl:text>Prima Query: estrae tutte le opere dei pittori </xsl:text> </td>   
          <td>   <xsl:value-of select = "/maestri/pittori"/>,</td> </tr>  
          
          <tr > <td> <xsl:text>Seconda Query: estrae tutte le opere d'arte </xsl:text></td>
          <td > <xsl:value-of select = "/*" />, </td>  </tr>
         
          <tr > <td> <xsl:text>Terza Query: estrae le opere dell'artista Michelangelo </xsl:text></td>
          <td > <xsl:value-of select = "/maestri/pittori/artista[@nome='Michelangelo']" />,</td></tr>
          
          <tr > <td> <xsl:text> Query 4: estrae la seconda e la quarta opera di Michelangelo </xsl:text> </td>
          <td > <xsl:value-of select = "/maestri/pittori/artista[@nome='Michelangelo']/opera[2]" /><span>,</span>
                <xsl:value-of select = "/maestri/pittori/artista[@nome='Michelangelo']/opera[4]" /></td></tr> 
          
          <tr > <td> <xsl:text> Query 5: estrae l'opera di Puccini del 1896 </xsl:text> </td>
          <td > <xsl:value-of select = "/maestri/musicisti/artista[@nome='Giacomo Puccini']/opera[@anno='1896']" /></td></tr>
          
          <tr > <td> <xsl:text> Query 6: estrae tutte le opere per ogni artista </xsl:text> </td>
          <td > <xsl:for-each select="/maestri/*/artista">
                <xsl:value-of select="@nome"/>:
                <xsl:for-each select="opera">
                <xsl:value-of select="concat(' ', @anno, ':', .)"/>
                </xsl:for-each> <div> - </div><br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 7: per ogni opera estrae anno e nome dell'artista</xsl:text> </td>
           <td> <xsl:for-each select="/maestri/*/artista/opera">
                <xsl:value-of select="../@nome"/>:
                <xsl:value-of select="concat(' ', @anno, ':', .)"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 8: per ogni artista estrae le opere e l'anno di esecuzione</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/artista">
                <xsl:value-of select="@nome"/>:
                <xsl:for-each select="descendant::opera">
                <xsl:value-of select="concat(' ', @anno, ':', .)"/>
                </xsl:for-each>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 9: per ogni opera estrae il nome dell'artista e l'anno di composizione e l'opera</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/artista/opera">
                <xsl:value-of select="ancestor::artista/@nome"/>:<!-- 24 11 2023 -->
                <xsl:value-of select="concat(' ', @anno, ':', .)"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 10: per ogni opera estrae il nome dell'artista e il numero di opere fatte</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/artista">
                <xsl:value-of select="@nome"/>: <xsl:value-of select="count(opera)"/>
                <br/>
                </xsl:for-each></td></tr> 
           <tr> <td> <xsl:text> Query 11: tra tutti i pittori sceglie il secondo e la sua ultima opera e ne estrae gli attributi</xsl:text> </td>     
           <td> <xsl:value-of select="//pittori//artista[2]/opera[last()]/text()">
                </xsl:value-of>
                <br/>
                </td></tr> 
           <tr> <td> <xsl:text> Query 12: estrae tutte le opere con anno che comincia con 14 con autore e anno</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/artista/opera[starts-with(@anno, '14')]">
                <xsl:value-of select="../@nome"/>: <xsl:value-of select="concat(@anno, ';', .)"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 13: estrae tutte le opere con anno >1880 con autore e anno 29-11-5L</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/artista/opera[number(@anno)> 1880]">
                <xsl:value-of select="../@nome"/>: <xsl:value-of select="concat(@anno, ';', .)"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 14: somma gli anni di tutte le opere</xsl:text> </td>     
           <td> <xsl:value-of select="sum(//opera/@anno)"></xsl:value-of>
                <br/>
                </td></tr>
           <tr> <td> <xsl:text> Query 15: selezione l'ultimo artista tra pittori e musicisti</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/artista[last()]">
                <xsl:value-of select="@nome"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 15: selezione l'ultimo artista tra pittori e musicisti</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/artista[last()]">
                <xsl:value-of select="@nome"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 16: selezione primo pittore e primo musicisti</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/artista[1]">
                <xsl:value-of select="@nome"/>
                <br/>
                </xsl:for-each></td></tr> 
           <tr> <td> <xsl:text> Query 17: per ogni artista 'Michelangelo'estrae il nome dell'artista e per ogni opera anche l'anno]</xsl:text> </td>     
           <td> <xsl:param name="targetName" select="'Michelangelo'"/>
                <xsl:for-each select="/maestri/*/artista[@nome=$targetName]">
                <xsl:value-of select="@nome"/>:
                <xsl:for-each select="opera">
                <xsl:value-of select="concat(' ', @anno, ':', .)"/>
                <xsl:if test="position() != last()">, </xsl:if>
                </xsl:for-each>
                <br/>
                </xsl:for-each></td></tr>                 
         </table>  
 
   </xsl:template>  
</xsl:stylesheet>  