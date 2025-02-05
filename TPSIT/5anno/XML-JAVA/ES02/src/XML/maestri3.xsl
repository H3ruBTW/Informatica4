<?xml version = "1.0" encoding = "UTF-8"?>  
<xsl:stylesheet version = "1.0" xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">     
   <xsl:template match = "/" >  
      
         <table border = "1" style="color:blue;font-size:40px" >
         
          <tr ><td> <xsl:text>Prima Query: estrae tutte le opere dei artisti </xsl:text> </td>   
          <td>   <xsl:value-of select = "/maestri/artisti[@tipo = 'pittura']"/>,</td> </tr>  
          
          <tr > <td> <xsl:text>Seconda Query: estrae tutte le opere d'arte </xsl:text></td>
          <td > <xsl:value-of select = "/*" />, </td>  </tr>
         
          <tr > <td> <xsl:text>Terza Query: estrae le opere dell'creatore Michelangelo </xsl:text></td>
          <td > <xsl:value-of select = "/maestri/artisti/creatore[@nome='Michelangelo']" />,</td></tr>
          
          <tr > <td> <xsl:text> Query 4: estrae la seconda e la quarta capolavoro di Michelangelo </xsl:text> </td>
          <td > <xsl:value-of select = "/maestri/artisti/creatore[@nome='Michelangelo']/capolavoro[2]" /><span>,</span>
                <xsl:value-of select = "/maestri/artisti/creatore[@nome='Michelangelo']/capolavoro[4]" /></td></tr> 
          
          <tr > <td> <xsl:text> Query 5: estrae l'capolavoro di Puccini del 1896 </xsl:text> </td>
          <td > <xsl:value-of select = "/maestri/artisti/creatore[@nome='Giacomo Puccini']/capolavoro[@anno='1896']" /></td></tr>
          
          <tr > <td> <xsl:text> Query 6: estrae tutte le opere per ogni creatore </xsl:text> </td>
          <td > <xsl:for-each select="/maestri/*/creatore">
                <xsl:value-of select="@nome"/>:
                <xsl:for-each select="capolavoro">
                <xsl:value-of select="concat(' ', @anno, ':', .)"/>
                </xsl:for-each> <div> - </div><br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 7: per ogni capolavoro estrae anno e nome dell'creatore</xsl:text> </td>
           <td> <xsl:for-each select="/maestri/*/creatore/capolavoro">
                <xsl:value-of select="../@nome"/>:
                <xsl:value-of select="concat(' ', @anno, ':', .)"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 8: per ogni creatore estrae le opere e l'anno di esecuzione</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/creatore">
                <xsl:value-of select="@nome"/>:
                <xsl:for-each select="descendant::capolavoro">
                <xsl:value-of select="concat(' ', @anno, ':', .)"/>
                </xsl:for-each>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 9: per ogni capolavoro estrae il nome dell'creatore e l'anno di composizione e l'capolavoro</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/creatore/capolavoro">
                <xsl:value-of select="ancestor::creatore/@nome"/>:<!-- 24 11 2023 -->
                <xsl:value-of select="concat(' ', @anno, ':', .)"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 10: per ogni capolavoro estrae il nome dell'creatore e il numero di opere fatte</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/creatore">
                <xsl:value-of select="@nome"/>: <xsl:value-of select="count(capolavoro)"/>
                <br/>
                </xsl:for-each></td></tr> 
           <tr> <td> <xsl:text> Query 11: tra tutti i artisti sceglie il secondo e la sua ultima capolavoro e ne estrae gli attributi</xsl:text> </td>     
           <td> <xsl:value-of select="//artisti//creatore[2]/capolavoro[last()]/text()">
                </xsl:value-of>
                <br/>
                </td></tr> 
           <tr> <td> <xsl:text> Query 12: estrae tutte le opere con anno che comincia con 14 con autore e anno</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/creatore/capolavoro[starts-with(@anno, '14')]">
                <xsl:value-of select="../@nome"/>: <xsl:value-of select="concat(@anno, ';', .)"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 13: estrae tutte le opere con anno >1880 con autore e anno 29-11-5L</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/creatore/capolavoro[number(@anno)> 1880]">
                <xsl:value-of select="../@nome"/>: <xsl:value-of select="concat(@anno, ';', .)"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 14: somma gli anni di tutte le opere</xsl:text> </td>     
           <td> <xsl:value-of select="sum(//capolavoro/@anno)"></xsl:value-of>
                <br/>
                </td></tr>
           <tr> <td> <xsl:text> Query 15: selezione l'ultimo creatore tra artisti e musicisti</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/creatore[last()]">
                <xsl:value-of select="@nome"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 15: selezione l'ultimo creatore tra artisti e musicisti</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/*/creatore[last()]">
                <xsl:value-of select="@nome"/>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 16: selezione primo pittore e primo musicisti</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/artisti[@tipo = 'pittura']/creatore[1]">
                <xsl:value-of select="@nome"/><br/>
                </xsl:for-each>
                <xsl:for-each select="/maestri/artisti[@tipo = 'musica']/creatore[1]">
                <xsl:value-of select="@nome"/>
                <br/>
                </xsl:for-each></td></tr> 
           <tr> <td> <xsl:text> Query 17: per ogni creatore 'Michelangelo'estrae il nome dell'creatore e per ogni capolavoro anche l'anno]</xsl:text> </td>     
           <td> <xsl:param name="targetName" select="'Michelangelo'"/>
                <xsl:for-each select="/maestri/*/creatore[@nome=$targetName]">
                <xsl:value-of select="@nome"/>
                <xsl:for-each select="capolavoro">
                <xsl:value-of select="concat(' ', @anno, ':', .)"/>
                <xsl:if test="position() != last()">, </xsl:if>
                </xsl:for-each>
                <br/>
                </xsl:for-each></td></tr>
           <tr> <td> <xsl:text> Query 18: Estrarre tutte le opere che seguono il primo creatore nella lista dei artisti.</xsl:text> </td>     
           <td> <xsl:for-each select="/maestri/artisti[@tipo = 'pittura']/creatore[1]/following::capolavoro">
                <xsl:value-of select="concat('capolavoro: ', ., ', Anno: ', @anno)" />
                <br/>
                </xsl:for-each>
                <xsl:for-each select="/maestri/artisti[@tipo = 'musica']/creatore[1]/following::capolavoro">
                <xsl:value-of select="concat('capolavoro: ', ., ', Anno: ', @anno)" />
                </xsl:for-each></td></tr>
            <tr>
            <td>
               <xsl:text> Query 19: estrae tutte le opere dei artisti con anno > 1500 e tecnica "olio su tela"</xsl:text>
            </td>
            <td>
               <xsl:for-each select="/maestri/artisti[@tipo = 'pittura']/creatore/capolavoro[@anno > 1500][@tecnica='olio su tela']">
                  <xsl:value-of select="concat('capolavoro: ', ., ', Anno: ', @anno, ', tecnica: ', @tecnica)"/>
                  <br/>
               </xsl:for-each>
            </td>
         </tr>
         <tr> 
    <td> 
        <xsl:text> Query 20: Estrai i nomi degli artisti che hanno più di 3 opere.</xsl:text> 
    </td>     
    <td> 
        <xsl:for-each select="/maestri/*/creatore[count(capolavoro) > 3]">
            <xsl:value-of select="@nome"/>
            <br/>
        </xsl:for-each>
    </td>
</tr>                                    
         </table>  
 
   </xsl:template>  
</xsl:stylesheet>  